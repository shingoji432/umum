//Tugas Komputasi Numerik
//Hitung Penyelesaian Vektor SPL dengan metode Eliminasi Gauss
//Nama : Muhammad Iqbal
//NIM  : A11.2021.13691
//Kel. : A11.4602
#include<iostream>
//Gunakan function math.h untuk memakai function abs()
#include<math.h>
using namespace std;

int main()
{
    char ulang = ' ';
    while(ulang != 'N'){
        int i,j,k,n = 0;

        cout << "\nMasukkan jumlah variable persamaan: ";
        cin >> n;

        // Membuat array 2 dimensi untuk memasukkan variabel persamaan kedalam suatu matriks augmented
        float matriks[n][n+1];

        // Membuat array untuk menampung nilai dari persamaan
        float hasil[n];

        cout << "Masukkan nilai-nilai dari variabel persamaan \n";
        cout << "Format input: \n";
        cout << "x11 x12 ... x1n\n";
        cout << "x21 x22 ... x2n\n";
        cout << "... ... ... ...\n";
        cout << "xm1 xm2 ... xmn\n";
        cout << endl;
        cout << "Masukkan nilai-nilai dari variabel persamaan: \n";

        for(i = 0; i < n; i++){
            for(j = 0; j < n + 1; j++){
                cin >> matriks[i][j];
            }
        }

        for(i = 0; i < n; i++){
            for(j = i + 1; j < n; j++){
                if(abs(matriks[i][i]) < abs(matriks[j][i])){
                    for(k = 0; k < n + 1; k++){
                        //Menukar mat[i][k] dan mat[j][k]
                        matriks[i][k] = matriks[i][k] + matriks[j][k];
                        matriks[j][k] = matriks[i][k] - matriks[j][k];
                        matriks[i][k] = matriks[i][k] - matriks[j][k];
                    }
                }
            }
        }

        //Melakukan eliminasi Gauss
        for(i = 0; i < n - 1; i++){
            for(j = i + 1; j < n; j++){
                float f = matriks[j][i] / matriks[i][i];
                for(k = 0; k < n + 1; k++){
                    matriks[j][k] = matriks[j][k] - f * matriks[i][k];
                }
            }
        }

        //Substitusi untuk mencari nilai dari variabel x1, x2, ..., xn
        for(i = n - 1; i >= 0; i--){
            hasil[i] = matriks[i][n];
            for(j = i + 1; j < n; j++){
                if(i != j){
                    hasil[i] = hasil[i] - matriks[i][j] * hasil[j];
                }
            }
            hasil[i] = hasil[i] / matriks[i][i];
        }

        cout<<"Nilai dari variabel persamaan \n";
        for(i = 0; i < n; i++){
            cout << "X" << i + 1 << "= " << hasil[i] << endl;
        }
        cout << "Lakukan operasi lagi? (Y / N) ";
        cin >> ulang;
    }
    return 0;
}
