//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)x.size())

const int maxN = 2 * 1000* 100 + 100; 
typedef long long ll;

int mark[maxN]; 
vector<int> c[maxN];
int dis[maxN];


bool dfs( int s , int p = -1  ) { 
	bool ret = mark[s]; 
	for( auto x : c[s] ) if( p != x ) 
		ret |= dfs( x ,s ) ; 
	if( ret ) mark[s] = 1; 
	return ret; 
}

void dd( int s , int p = -1 , int h = 0 ) { 
	dis[s] = h; 
	for( auto x : c[s] ) if( x != p && mark[x] ) 
		dd( x , s , h + 1 ); 
}

int main() { 
	int n,q; 
	cin >> n >> q;
	for( int i = 0 ; i < n - 1 ; i++ ) { 
		int a,b; cin >> a >> b; 
		a--; b--; 
		c[a].push_back(b); 
		c[b].push_back(a); 
	}
	int st =  -1; 
	for( int i = 0 ; i < q ; i++ ) { 
		int x ; cin >> x; 
		x--; 
		mark[x] = true; 
		st = x; 
	}
	dfs( st ) ; 
	int ans = 0; 
	for( int i = 0 ; i < n ; i++ ) if( mark[i] ) 
		for( auto x : c[i] ) if( mark[x] ) 
			ans++; 
	memset( dis , -1 , sizeof dis ); 
	dd( st ); 
	pair<int,int> best = { -1 , 1 } ; 
	for( int i = 0 ; i < n ; i++ ) 
		best = max( best , { dis[i] , -i } ) ; 
	int x = -best.second ;
	memset( dis , -1 , sizeof dis ); 
	dd( x ) ; 
	best = { -1 , 1 } ; 
	for( int i = 0 ; i < n ; i++ ) 
		best = max( best , { dis[i] , -i } ) ; 
	int y = -best.second;
	cout << min(x,y) + 1 << endl;
	cout << ans - *max_element( dis , dis + n ) << endl;
}