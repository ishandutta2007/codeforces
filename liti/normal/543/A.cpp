//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define sz(x) ((int)(x).size())    
typedef long long ll;    
int n,m,b,mod;

int bpow( int a , int b ) { 
    int res = 1;
    for( ; b ; b /= 2 ) { 
	if( b & 1 ) 
	    res = res * 1ll * a % mod; 
	a = a * 1ll * a % mod; 
    }
    return res;
}

const int maxN = 500 + 10;
int a[maxN];
int dp[maxN][maxN]; // i lines and j bugs
int cmp[2*maxN][2*maxN];

vector<pair<int,int>> x; 

inline int add( int a , int b ) { 
    int c = ( a + b ) ; 
    if( c >= mod ) c -= mod;
    return c;
}
int main() { 
    cin >> n >> m >> b>> mod;

    for( int i = 0 ; i < n ; i++ ) 
	cin >> a[i];
    sort( a , a + n ) ; 
    dp[0][0] = 1;
    for( int t = 0 ; t < n ; t++ ) 
	for( int i = 1 ; i < maxN - 1 ; i++ )
	    for( int j = 0 ; j < maxN - 1 ; j++ ) 
		if( j - a[t] >= 0 ) 
		    dp[i][j] = add( dp[i][j] , dp[i-1][j-a[t]]) ;
    int ans = 0;
    for( int i = 0 ;i <= b ; i++ ) 
	ans = add( ans , dp[m][i] ) ; 
    cout << ans << endl;
}