//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll; 

const int maxN = 200 * 1000 + 100; 
bool good[maxN],marz[maxN]; 
bool mark[maxN];
int deg[maxN];
int val[maxN];
int par[maxN];
int a[maxN]; 
vector<int> c[maxN]; 
queue<int> curr; 

void dfs( int s , bool add = false , int p = -1 ) { 
	val[s] = 1;
	par[s] = p;
	mark[s] = true;
	int cnt = 0;
	for( auto x : c[s] ) { 
		if( good[x] && !mark[x] ) 
			dfs(x,add,s); 
		if( good[x] ) cnt++; 
	}
	if( !add && cnt != (int)c[s].size() ) marz[s] = true;
	if( add && c[s].size() == 1 && good[c[s][0]] ) 
		curr.push(s);
}

int lp[maxN],dp[maxN]; 

void solve( int s , int p = -1 ) { 
	mark[s] = 0; 
	dp[s] = lp[s] = val[s];
	for( auto x : c[s] ) if( x != p && mark[x] ) { 
		solve(x,s);
		dp[s] = max( dp[s] , max( dp[x] , lp[x] + lp[s] ) ) ; 
		lp[s] = max( lp[s] , lp[x] + val[s] ); 
	}
}

int main() { 
	ios::sync_with_stdio(false);
	int n,k; cin >> n >> k; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	for( int i = 0 ; i < n - 1 ; i++ ) {
		int a,b; cin >> a >> b; 
		a--; b--; 
		c[a].push_back(b); 
		c[b].push_back(a); 
	}

	int s = 0 , e = 1000 * 1000 + 100; 
	while( e - s > 1 ) { 
		int mid = (s+e)/2; 
		for( int i = 0 ; i < n ; i++ ) { 
			good[i] = (a[i] >= mid);
			deg[i] = c[i].size(); 
		}

		memset( mark , 0 , sizeof mark ); 
		memset( marz , 0 , sizeof marz ) ; 
		memset( val , 0 , sizeof val );
		for( int i = 0 ; i < n ; i++ ) 
			if( good[i] && !mark[i] ) 
				dfs(i); 
		memset( mark , 0 , sizeof mark ); 
		memset( par , -1 , sizeof par );
		for( int i = 0 ; i < n ; i++ ) 
			if( good[i] && marz[i] && !mark[i] ) 
				dfs(i,1); 
		for( int i = 0 ; i < n ; i++ ) 
			if( good[i] && !mark[i] ) 
				dfs(i,1); 

		while( curr.size() ) { 
			int s = curr.front(); 
			curr.pop(); 
			if( par[s] == -1 ) continue;
			val[par[s]] += val[s]; 
			deg[par[s]]--; 
			mark[s] = 0; 
			if( par[par[s]] != -1 && deg[par[s]] == 1 )
				curr.push(par[s]); 
		}


		memset( dp , 0 , sizeof dp ); 
		memset( lp , 0 , sizeof lp );
		bool check = false;
		for( int i = 0 ; i < n ; i++ ) 
			if( mark[i] ) { 
				solve(i) ;
//				cerr << i+1 << ' ' << dp[i] << endl;
				if( dp[i] >= k ) 
					check = true;
			}

		if( check ) 
			s = mid; 
		else
			e = mid;
	}
	cout << s << endl;
}