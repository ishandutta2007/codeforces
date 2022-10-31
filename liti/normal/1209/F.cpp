//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int mod = 1e9 + 7; 

const int N = 1000 * 1000 + 10;
int n;

int h[N], mark[N], cnt; 
int ans[N]; 

vector<pii> c[N]; 

int que[N], qen; 

void solve(set<int> s, int cur) {
	for( auto x : s ) { 
		mark[x] = true; 
		if( x <= n ) 
			ans[x] = cur; 

	}
	

	map<int, short> mp; 

	for( auto x : s ) 
		for( auto y : c[x] ) 
			if( h[y.F] == h[x] + 1 && mark[y.F] == false ) { 
				if( mp.count(y.F) == 0 ) 
				   mp[y.F] = y.S; 	
				else
					mp[y.F] = min((int)mp[y.F], y.S); 
			}

	set<int> child[10]; 

	for( auto x : s ) 
		for( auto y : c[x] ) 
			if( h[y.F] == h[x] + 1 && mark[y.F] == false ) 
				child[mp[y.F]].insert(y.F); 

	for(int i = 0; i < 10; i++) 
		if( child[i].size() ) 
			solve(child[i], (1ll * cur * 10 + i) % mod); 
}

void handle(int u, int v, int i) { 
	int cur = v; 
	while( i != 0 ) { 
		if( i / 10 == 0 ) { 
			c[u].pb({cur, i%10}); 
			break;
		}
		c[cnt].pb({cur, i%10});

		cur = cnt;
		cnt++; 
		
		i /= 10; 
	}
}

int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 

	int m;
	cin >> n >> m;

	cnt = n+1; 

	for(int i = 1; i <= m; i++) { 
		int u, v;
		cin >> u >> v; 

		handle(u, v, i); 
		handle(v, u, i); 
	}

	memset(h, -1, sizeof h); 

	que[qen++] = 1; 
	h[1] = 0; 
	for(int i = 0; i < qen; i++) { 
		int s = que[i]; 

		for(auto x : c[s]) 
			if( h[x.F] == -1 ) { 
				h[x.F] = h[s] + 1; 
				que[qen++] = x.F; 
			}
	}

	set<int> beg;
	beg.insert( 1 ); 

	solve(beg, 0); 

	for(int i = 2; i <= n; i++) 
		cout << ans[i] << '\n';

    return 0;
}