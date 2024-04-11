//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define sz(x) ((int)(x).size())    
typedef long long ll;    

const int mod = 1e9 + 7;
inline int add( int a , int b ) { 
    int c = a + b; 
    if( c >= mod ) c-= mod;
    return c;
}

const int maxN = 200*1000 + 100; 
typedef vector<int> C[maxN];
C c,l,r;
int ind[maxN];
int dp[maxN]; 
int ans[maxN];

void dfs( int s , int p = -1 ) { 
    dp[s] = 1;
    for( auto x : c[s] ) if( x != p ) { 
	dfs( x , s ) ; 
	dp[s] = dp[s]* 1ll * ( dp[x] + 1 )  % mod; 
    }
}
void sfs( int s , int p = -1 ) { 
    ans[s] = 1; 

    l[s][0] = 1;
    for( int i = 0 ; i < sz(c[s]) ; i++ ) { 
	int x = c[s][i] ; 
	int tmp;
	if( x != p ) tmp = dp[x] + 1;
	else tmp = (l[x][ind[s]] * 1ll * r[x][ind[s]]+1) % mod;
	ans[s] = ans[s] * 1ll * tmp % mod;
	if( i == sz(c[s]) - 1 ) continue;
	l[s][i+1] = (l[s][i] * 1ll * tmp) % mod;
    }
    r[s][sz(c[s])-1] = 1;
    for( int i = sz(c[s]) - 1 ; i > 0 ; i-- ) {
	int x = c[s][i] ; 
	int tmp;
	if( x != p ) tmp = dp[x] + 1;
	else tmp = (l[x][ind[s]] * 1ll * r[x][ind[s]]+1) % mod;
	r[s][i-1] = r[s][i] * 1ll * tmp % mod;
    }
    for( auto x : c[s] ) if( x != p ) 
	sfs(x,s);
}

int main() { 
    ios::sync_with_stdio(false); cin.tie(0);
    int n; 
    cin >> n;
    for( int i = 1 ; i <n ; i++ ) { 
	int p; cin >> p; p--; 
	c[i].push_back( p ) ; 
	c[p].push_back( i ) ;
	ind[i] = sz(c[p])-1;
    }
    for( int i = 0 ; i < n ; i++ ) {
	r[i].resize( sz(c[i]) ) ;
	l[i].resize( sz(c[i]) ) ;
    }
	


    dfs( 0 ) ; 
    sfs( 0 ) ; 

    for( int i = 0 ; i <n ; i++ ) 
	cout << ans[i] << ' ' ;
    cout << endl;
}