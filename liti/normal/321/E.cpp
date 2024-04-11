/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;
#define sz(x) (((int) x.size()))

const int maxN = 4000 + 10; 
const int maxK = 800 + 10;

int a[maxN][maxN];

int dp[maxK][maxN];
int u[maxK][maxN];

inline int getSum( int i , int j ) { 
    return a[j][j] - a[i][j] - a[j][i] + a[i][i]; 
}

int main() { 
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;

    for( int i = 1 ; i <= n; i++ ) 
        for( int j = 1 ; j <= n ; j++ ) {
            cin >> a[i][j];
                        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    for( int i = 0; i <= k ; i++ ) 
        u[i][n+1] = n;

    fill( (int*)dp , &dp[maxK][maxN] , 1e9 ) ;
    dp[0][0] = 0;

    for( int i = 1 ; i <= k ; i++ ) 
        for( int j = n ; j > 0 ; j-- ) { 
            pair<int,int> best = {1e9,-1};
            for( int x = u[i-1][j] ; x <= u[i][j+1]; x++ ) { 
                static int cnt = 0;
                cnt++;
                assert( cnt <= 4*n*n ) ;
                pair<int,int> tmp = {dp[i-1][x] + getSum(x,j) , x};
                if( tmp < best ) 
                    best = tmp;
            }
            dp[i][j] = best.first;
            u[i][j] = best.second;
        }
    cout << dp[k][n]/2 << endl;
}