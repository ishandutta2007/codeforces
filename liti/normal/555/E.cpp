//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define __sz(x) ((int)(x).size())

const int maxN = 2 * 1000 * 100 + 10; 
vector<int> c[maxN];
int p[maxN]; 
int st[maxN];
int used[maxN];

int dfind( int u ) { 
	return p[u] == -1 ? u : p[u] = dfind( p[u] ) ; 
}
void dmerge( int u , int v ) { 
	u = dfind( u ) ; v = dfind( v ) ; 
	if( u != v ) 
		p[u] = v; 
}

int num[maxN];
int dfs( int s , int p =0  ) { 
	static int ind = 0; 
	num[ind] = s; 
	st[s] = ind++;
	int lo = st[s];
	used[s] = true;
	bool ch = false;
	for( auto x : c[s] ) { 
		if( used[x] ==  0 ) 
			lo = min( lo , dfs( x , s ) ); 
		else if( x == p && !ch ) { 
			ch = true; 
		} else { 
			lo = min( lo , st[x] ) ; 
		}
	}
	if( lo != st[s] ) 
		dmerge( st[s] , st[p] ) ; 
	return lo;
}

vector<int> e[maxN];

const int maxL = 20; 
int h[maxN];
int par[maxN][maxL];
int co[maxN];
void pre( int s , int p , int co ) { 
	::co[s] = co;
	par[s][0] = p;
	h[s] = h[p] + 1; 
	for( int k = 1 ; k < maxL ; k++ ) 
		par[s][k] = par[par[s][k-1]][k-1];
	for( auto x : e[s] ) if( x != p ) 
		pre( x , s , co ) ; 
}

int up[maxN] , down[maxN];
bool ans = true;

void doJob( int s , int p = 0 ) { 
	for( auto x : e[s] ) 
		if( x != p ) { 
			doJob( x , s ) ; 
			down[s] += down[x]; 
			up[s] += up[x];
		}
	if( s != 0 && up[s] && down[s] ) 
		ans = false;
}

int gg( int u , int h ) { 
	for( int i = 0 ; i < maxL ; i++ ) 
		if( h & (1<<i) ) 
			u = par[u][i];
	return u;
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	memset( p , -1 , sizeof p ) ;
	int n,m,q; 
	cin >> n >> m >> q;
	for( int i = 0 ; i < m ; i++) { 
		int u,v; 
		cin >> u >> v; 
		u--; v--; 
		c[u].push_back( v ) ; 
		c[v].push_back( u ) ; 
	}
	for( int i = 0 ; i < n ; i++ ) if( !used[i] ) 
		dfs( i , i ) ; 

	for( int i = 0 ; i < n ; i++ ) 
		for( auto x : c[i] ) if(dfind(st[x]) != dfind(st[i])) {
			e[dfind(st[i])].push_back(dfind(st[x])) ; 
	//		cout << dfind(st[i]) << ' ' << dfind(st[x]) << endl;
		}

	for( int i = 0 ; i < n ; i++ ) if(dfind(i) == i && !h[i])
		pre( i , i , i ) ; 

	for( int i = 0 ; i < q ; i++ ) { 
		int u ,v ; 
		cin >> u >> v; u--; v--; 
		u = dfind(st[u]); 
		v = dfind(st[v]);
		if( co[v] != co[u] ) { 
			cout << "No" << endl;
			return 0;
		}
		int uu = u , vv = v;
		if( h[u] > h[v] ) 
			u = gg( u , h[u] - h[v] ) ;
		else if( h[v] > h[u] ) 
			v = gg( v , h[v] - h[u] ) ; 
		int w ; 
		if( u == v ) 
			w = u; 
		else { 
			for( int k = maxL - 1 ; k >= 0 ; k-- ) 
				if( par[u][k] != par[v][k] ) { 
					u = par[u][k]; 
					v = par[v][k];
				}
			w = par[u][0];
		}
		up[uu]++; 
		up[w]--; 
		down[vv]++;
		down[w]--;
	}

	doJob( 0 ) ; 
	if( ans ) 
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}