/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 30000 + 10;
const int maxK = 2000 + 10; 

int dp[maxN][maxK];
int a[maxN];

void smax( int& a , int b ) { 
	a = max( a , b ) ; 
}

int main() { 
	int n,d;
	cin >> n >> d; 
	for( int i = 0 ; i < n ; i++ ) { 
		int x; cin >> x; 
		a[x] ++;
	}
	memset( dp , -1 , sizeof dp ) ;
	dp[d][1000] = a[d];
	int ret = a[d];
	for( int i = d ; i < 30001 ; i++ ) 
		for( int j = 0 ; j < maxK ; j++ ) {
			if( dp[i][j] == -1 ) continue;
			ret = max( ret , dp[i][j] ) ;
			int x = d + j - 1000;
			if( i + x + 1 < maxN && j + 1 < maxK ) 
				smax(dp[i+x+1][j+1] ,dp[i][j] + a[i+x+1]);
			if( i + x < maxN ) 
				smax(dp[i+x][j] , dp[i][j] + a[i+x]);
			if( x - 1 > 0 && i + x - 1 < maxN && j - 1 > 0 ) 
				smax(dp[i+x-1][j-1] , dp[i][j] + a[i+x-1]);
		}
	cout << ret << endl;
}