#include <bits/stdc++.h>
using namespace std;

int f[31][31][51];

int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt","w",stdout);
   ios_base::sync_with_stdio(false);
   for ( int n = 1; n <= 30; n++) {
         for ( int m = 1; m <= 30; m++) {
            for ( int k = 1; k <= min(n*m,50); k++) {
                 if ( k == n*m) {
                 f[n][m][k]  = 0;
                 }
                 else f[n][m][k] = 1e9;

            }
        }
   }
   f[1][1][1] = 0;
   for ( int n = 1; n <= 30; n++) {
        for ( int m = 1; m <= 30; m++) {
            for ( int k = 1; k <= min(n*m,50); k++) {
                 for ( int j = 0; m + j <= 30; j++) {
                     for ( int k1 = 0; k1 <= min(n*j,50);k1++) {
                     if ( k + k1 <= 50) {
                     f[n][m+j][k+k1] = min( f[n][m+j][k+k1], f[n][m][k] + n*n+f[n][j][k1]);
                     }
                 }
                }
                 for ( int j = 0; n + j <= 30; j++) {
                     for ( int k1 = 0; k1 <= min(m*j,50);k1++) {
                     if ( k + k1 <= 50) {
                     f[n+j][m][k+k1] = min( f[n+j][m][k+k1], f[n][m][k] + f[j][m][k1]+m*m);
                        }
                      }
                   }
                 }
              }
            }
   int t;
   cin>>t;
   for ( int i = 1; i <= t; i++) {
        int x,y,z;
        cin>>x>>y>>z;
        cout<<f[x][y][z]<<endl;
   }
   return 0;
}