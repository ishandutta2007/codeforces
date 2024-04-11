//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    

const int maxN = 1000*100 + 100; 
const int maxL = 20; 
typedef int Arr[maxN][maxL];

vector<int> c[maxN];
Arr par , up , down; 
int mxDown[maxN] ,mxUp[maxN];
pair<int,int> mxd[maxN][3], mxtmp[maxN];
int ll[maxN] , rr[maxN], h[maxN];

inline int get_mxd(int s , int p = 0 ) { 
	for( int i = 0 ; i < __sz(c[s]) ; i++ ) 
		if( c[s][i] == p ) { 
			c[s].erase( c[s].begin() + i ) ; 
			break;
		}
	for( auto x : c[s] )
		mxDown[s] = max( mxDown[s] , 1 + get_mxd(x,s) ) ; 

	int cnt = 0;
	for( int i = 0 ; i < 3 ; i++ ) mxtmp[i] = {-1,-1};
	for( auto x : c[s] ) 
		mxtmp[cnt++] = { mxDown[x] + 1 , x } ; 
	sort(mxtmp , mxtmp + cnt,greater<pair<int,int>>()); 
	copy( mxtmp , mxtmp + 3 , mxd[s] ) ;

	return mxDown[s];
}
inline void prep( int s , int p = 0 , int h = 1 ) { 
	::h[s] = h;
	par[s][0] = p; 
	up[s][0] = mxUp[s] + 1;
	down[s][0] = mxUp[s];
	mxUp[s] = max( mxUp[s] + 1 , mxUp[p] + 1 );
	for( int k = 1 ; k < maxL ; k++ ) { 
		par[s][k] = par[par[s][k-1]][k-1];
		up[s][k] = max( up[s][k-1] , (1<<(k-1)) + up[par[s][k-1]][k-1] );
		down[s][k] = max( down[s][k-1] + (1<<(k-1)) , down[par[s][k-1]][k-1] ) ; 
	}
	int sz = __sz(c[s]);
	for( int i = 0 ; i < sz - 1 ; i++ ) 
		ll[i+1] = max( ll[i] , mxDown[c[s][i]] + 1 ) ; 
	if( sz ) 
		rr[sz-1] = 0;
	for( int i = sz - 1 ; i > 0 ; i-- ) 
		rr[i-1] = max(rr[i] , mxDown[c[s][i]] + 1 ) ; 
	for( int i = 0 ; i < sz ; i++ ) 
		mxUp[c[s][i]] = max( ll[i] , rr[i] ) ; 
	for( int i = 0 ; i < sz ; i++ ) 
		prep( c[s][i] , s , h + 1 ) ; 
}
inline int goUp( int u , int h ) { 
	for( int k = 0 ; k < maxL ; k++ ) 
		if( (h>>k) & 1 ) 
			u = par[u][k]; 
	return u;
}

int ans;
inline int lca( int u , int v ) { 
	int tmp = min(h[u],h[v]);
	if( h[u] > h[v] ) u = goUp( u , h[u] - h[v] ) ; 
	else v = goUp( v , h[v] - h[u] ) ; 
	if( u == v ) return u;
	for( int k = maxL - 1 ; k >= 0 ; k-- ) 
		if( par[u][k] != par[v][k] ) { 
			u = par[u][k];  
			v = par[v][k];
		}
	int w = par[u][0];
	for( int i = 0 ; i < 3 ; i++ ) 
		if( mxd[w][i].second != u && mxd[w][i].second != v && mxd[w][i].second != -1 ) 
			ans = max( ans , mxd[w][i].first + tmp - h[w] ); 
	return w;
}

inline int calcUp( int u , int mid , int m = 0 ) { 
	int x = h[u] - h[mid] - m;
	if( x <= 0 ) return 0;
	int ans = 0;
	int val = 0;
	for( int k = 0 ; k < maxL ; k++ ) 
		if( (x>>k) & 1 ) { 
			ans = max( ans , val + up[u][k] ) ; 
			val += (1<<k);
			u = par[u][k];
		}
	return ans;
}
inline int calcDown( int u , int mid ) { 
	int x = h[mid] - h[u] - 1;
	if( x <= 0 ) return 0;
	int ans = 0;
	for( int k = 0 ; k < maxL ; k++ ) 
		if( (x>>k) & 1 ) { 
			ans = max( ans , (h[mid] - (1<<k)) - h[u] + down[mid][k] ) ; 
			mid = par[mid][k]; 
		}
	return ans;
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for( int i = 0 ; i < n-1 ; i++ ) { 
		int u,v; cin >> u >> v;
		c[u].push_back( v ) ; 
		c[v].push_back( u ) ; 
	}
	memset( up , -10 , sizeof up ) ; 
	memset( down , -10 , sizeof down ) ; 
	memset( mxUp , -10 , sizeof mxUp ) ; 
	get_mxd(1); // get mx down
	prep(1); // prepare mx up and lca

	int q; cin >> q;
	for( int i = 0 ; i < q ; i++ ) { 
		ans = 0;
		int u,v; cin >> u >> v;
		int w = lca( u , v ); 
		//cerr << "$## " << u<< ' ' << v << ' ' << w << endl;
		//cerr << "2 " << ans << endl;
		int mn = (h[u] + h[v] - 2 * h[w])/2;
		if( h[u] < h[v] ) swap( u , v ); // u is lower eq than v 

		ans = max(ans,mxUp[w]+h[v]-h[w]);
		//cerr << "3 " << ans << endl;

		ans = max(ans,mxDown[u]);
		//cerr << "4 " << ans << endl;

		if( v != w ) ans = max( ans , mxDown[v] ); 

		//cerr << "5 " << ans << endl;

		int mid = goUp( u , mn ) ; 
		//cerr << "DBG " << mid << endl;
		if( mid != w ) 
			ans = max( ans , calcUp(u,mid) ); 
		else
			ans = max( ans , calcUp(u,mid,1) );
		//cerr << "6 " << ans << endl;
		if( v == w ) 
			ans = max( ans , calcDown(par[w][0],mid) - 1 );
		else
			ans = max( ans , calcDown(w,mid) + h[v] - h[w] ); 
		//cerr << "7 " << ans << endl;
		ans = max( ans , calcUp(v,w,1) ); 
		//cerr << "8 " << ans << endl;
		cout << ans << '\n';
	}
}