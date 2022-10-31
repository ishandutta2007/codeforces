//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii; 
#define div divoone

const int maxN = 200 * 1000 + 500; 
int a[maxN]; 
vector<int> div[maxN], c[maxN]; 
int cnt[maxN]; 
int dp[maxN], hp[maxN]; 

inline void add(int v, int z) { 
	for( auto x : div[v] ) 
		cnt[x] += z; 
}

void dfs(int s, int p, int h) { 
	hp[s] = __gcd(hp[p],a[s]);
	dp[s] = hp[p]; 

	add( a[s] , 1 ); 
	for( auto x : div[a[s]] ) 
		if( cnt[x] >= h ) 
			dp[s] = max( dp[s] , x ); 
	for( auto x : c[s] ) 
		if( x != p ) 
			dfs( x , s , h + 1 ); 

	add( a[s] , -1 ); 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for( int i = 1 ; i < maxN ; i++ ) 
		for( int j = i ; j < maxN ; j+=i ) 
			div[j].push_back( i ); 

	int n; cin >> n;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	for( int i = 0 ; i + 1 < n ; i++ ) {
		int u, v;
		cin >> u >> v;
		u--; v--; 
		c[u].push_back(v);
		c[v].push_back(u);
	}
	hp[0] = dp[0] = a[0]; 
	add( a[0] , 1 );
	for( auto x : c[0] ) 
		dfs( x , 0 , 1 ); 
	for( int i = 0 ; i < n ; i++ )
		cout << dp[i] << " ";
	cout << endl;
}