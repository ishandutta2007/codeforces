//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge { 
	int u,v,w,id;
};
bool cmp( edge a , edge b ) { 
	return a.w > b.w; 
}

const int maxN = 1000 + 10; 
const int maxM = maxN * maxN; 

edge e[maxM];

struct DSU { 
	DSU() { 
		memset( par , -1 , sizeof par );
		memset( co , 0 , sizeof co );
		for( int i = 0 ; i < maxN ; i++ ) 
			sz[i] = 1; 
	}
	int dfind( int u ) { 
		if( par[u] == -1 ) return u; 
		int ret = dfind(par[u]); 
		co[u] ^= co[par[u]]; 
		par[u] = ret; 
		return ret; 
	}
	inline int dco( int u ) { 
		dfind(u); 
		return co[u]; 
	}
	inline bool dmerge( int u , int v ) { 
		int pu = dfind(u), pv = dfind(v); 
		if( pu == pv ) return co[u] != co[v];
		if( sz[pu] < sz[pv] ) { 
			swap(pu,pv);
			swap(u,v); 
		}
		if( co[u] == co[v] )
			co[pv] ^= 1; 
		par[pv] = pu;
		sz[pu] += sz[pv];
		return true;
	}


	int par[maxN]; 
	int sz[maxN]; 
	bool co[maxN];
};
DSU d[maxN];

pair<int,int> q[maxN],a[maxN]; 
int ans[maxN];


int main() {
	ios::sync_with_stdio(false); cin.tie(0); 
	int n,m,t; cin >> n >> m >> t; 
	for( int i = 0 ; i < m ; i++ ) { 
		cin >> e[i].u >> e[i].v >> e[i].w; 
		e[i].u--; e[i].v--;
		e[i].id = i;  
	}
	sort( e , e + m , cmp ); 
	for( int i = 0 ; i < t ; i++ )  { 
		cin >> q[i].first >> q[i].second; 
		q[i].first--;
		ans[i] = -1; 
	}

	
	for( int j = 0 ; j < t ; j++ ) 
		for( int i = 0 ; i < m ; i++ ) 
			if( ans[j] == -1 && q[j].first <= e[i].id && e[i].id < q[j].second ) {
			//	cout << "HI" << endl;
				if( !d[j].dmerge( e[i].u , e[i].v ) ) { 
					ans[j] = e[i].w; 
					break;
				}
			}
	for( int i = 0 ; i < t ; i++ ) 
		cout << ans[i] << '\n'; 
}