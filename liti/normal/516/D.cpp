/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*100 + 10;
vector<pair<int,int>> c[maxN];

ll dist[maxN] , _dist[maxN];

inline void dfs( int s , ll* dist , int p = -1 ) { 
	for( auto x : c[s] ) if( x.first != p ) { 
		dist[x.first] = dist[s] + x.second;
		dfs( x.first , dist , s )  ;
	}
}

ll l;

int st[maxN] , en[maxN];
int ind;
inline void findOrder( int s , int p = -1 ) { 
	st[s] = ind++; 
	for( auto x : c[s] ) if( x.first != p ) 
		findOrder( x.first , s ) ;
	en[s] = ind;
}

pair<ll,int> mx[4*maxN];
int n;

inline void sVal( int p , ll v , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xl == p && xr == p + 1 ) {
		mx[ind] = {v,xl};
		return;
	}
	int xm = (xl+xr) / 2 ; 
	if( p < xm ) sVal( p , v , xl , xm , ind * 2 );
	else sVal( p , v , xm , xr , ind * 2 + 1 ) ; 
	mx[ind] = max(mx[ind*2] , mx[ind*2+1]);
}
inline pair<ll,int> gVal( int ql , int qr , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( ql <= xl && xr <= qr ) 
		return mx[ind];
	int xm = (xl+xr)/2;
	pair<ll,int> ret = {-1,-1};
	if( ql < xm ) 
		ret = gVal( ql , qr , xl , xm , ind * 2 ) ; 
	if( qr > xm ) 
		ret = max(ret,gVal(ql, qr, xm , xr , ind * 2 + 1 ) ) ;
	return ret;
}

int ret;
inline int doJob( int s , int p = -1 ) { 
	int removed = 0;
	for( auto x : c[s] ) if( p != x.first ) 
		removed += doJob( x.first , s ) ;
	pair<ll,int> ind;
	while( ( ind = gVal( st[s] , en[s] ) ).first > dist[s] + l ) {
		removed++;
		sVal( ind.second , 0 );
	}
	ret = max( ret , en[s] - st[s] - removed ) ;
	return removed;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;

	for( int i = 0 ; i < n - 1 ; i ++ ) { 
		int u,v,w;
		cin >> u >> v >> w;
		u--; v--;
		c[u].push_back({v,w});
		c[v].push_back({u,w});
	}
	dfs(0,dist);
	int f = max_element(dist,dist+n) - dist;
	dist[f] = 0;
	dfs(f,dist);
	int s = max_element(dist,dist+n) - dist;
	dfs(s,_dist);

	for( int i = 0 ; i < n ; i++ ) dist[i] = max(dist[i],_dist[i]);
	int center = min_element( dist , dist + n ) - dist;

	findOrder(center);

	int q; cin >> q;
	for( int i = 0 ; i < q ; i++ ) { 
		cin >> l; 
		for( int j = 0 ; j < n ; j++ ) 
			sVal( st[j] , dist[j] ) ; 
		ret = 0;
		doJob( center ) ; 
		cout << ret << '\n';
	}
}