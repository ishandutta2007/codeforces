/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
#define rep(i,n) for( int i = 0 ; i < n ; i++ ) 
typedef long long ll;

const int maxK = 100 + 10;
const int maxL = 31;
const int mod = 1e9 + 7;

int mat[maxL][maxK][maxK], ans[maxK][maxK], tmp[maxK][maxK];

int main() { 
	int m,x;
	cin >> m >> x;
	for( int i = 0 ; i < m ; i++ ) { 
		int num;
		cin >> num;
		mat[0][0][num-1]++;
	}

	int n = 101;
	mat[0][0][n-1] = 1;
	for( int i = 0 ; i < 99 ; i++ ) 
		mat[0][i+1][i] = 1;
	mat[0][n-1][n-1] = 1;

	for( int i = 0 ; i < n ; i++ ) 
		ans[i][i] = 1;
	for( int t = 1 ; t < maxL ; t++ ) {
		rep( i , n ) rep( k , n ) rep( j , n ) {
			mat[t][i][j] += mat[t-1][i][k] * 1ll * mat[t-1][k][j] % mod;
			if( mat[t][i][j] >= mod ) 
				mat[t][i][j] -= mod;
		}
	}

	for( int t = 0 ; t < maxL ; t++ ) 
		if( (1<<t) & x ) {
			memset(tmp,0,sizeof tmp);
			rep( i , n ) rep( k , n ) rep( j , n ) {
				tmp[i][j] += ans[i][k] * 1ll * mat[t][k][j] % mod;
				if( tmp[i][j] >= mod ) 
					tmp[i][j] -= mod;
			}
			swap(tmp,ans);
		}
	int ret =( ans[0][0] + ans[0][100]) % mod;
	cout << ret << endl;

}