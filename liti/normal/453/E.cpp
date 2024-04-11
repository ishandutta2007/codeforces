//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii; 
typedef pair<pii,pii> Que; // <<time,index>,<s,e>>
typedef long long ll;

const int maxN = 1000 * 100 + 100; 
Que que[10*maxN]; int en;  
ll fen[2][maxN]; 
inline void add( int id, int x , int v ) { 
	x++; 
	for( ; x < maxN ; x += x & -x ) 
		fen[id][x] += v; 
}
inline ll get( int id , int x ) { 
	ll ret = 0; 
	for( ; x ; x -= x & -x )
		ret += fen[id][x]; 
	return ret; 
}

set<pair<pair<int,int>,int>> curr; 
ll ans[maxN]; 

struct Pony { 
	int s , m , r; 
} a[maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 

	int n; cin >> n; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i].s >> a[i].m >> a[i].r; 

	int m; cin >> m;
	for( int q = 0 ; q < m ; q++ ) { 
		int t , l , r; cin >> t >> l >> r; 
		l--; 
		for( int i = l ; i < r ; i++ ) { 
			auto x = curr.upper_bound( { { i , n + 1 } , n } ); 
			if( x == curr.begin() || (--x, x->first.second <= i) )
				ans[q] += min( t * 1ll * a[i].r + a[i].s , a[i].m * 1ll ); 
			else { 
				int xl = x->first.first , xr = x->first.second; 
				int lt = x->second;
				int ql = i , qr = min( r , xr ); 
				curr.erase( x ); 
				que[en++] = { { t - lt , q } , { ql , qr } }; 
				if( xl < ql ) 
					curr.insert( { { xl , ql } , lt } ); 
				if( qr < xr ) 
					curr.insert( { { qr , xr } , lt } ); 
				i = qr - 1; // i should get++ nex time
			}
		}
		curr.insert( { {l,r} , t } ); 
	}

	for( int i = 0 ; i < n ; i++ ) 
		if( a[i].r ) 
			que[en++] = { { a[i].m / a[i].r + 1 , -1 } , { i , i } }; 
	sort( que , que + en ); 

	for( int i = 0 ; i < n ; i++ ) 
		add( 1 , i , a[i].r ); 

	for( int i = 0 ; i < en ; i++ ) { 
		if( que[i].first.second == -1 ) { 
			int x = que[i].second.second;
			add( 0 , x , a[x].m ); 
			add( 1 , x , -a[x].r ); 
		} else { 
			int ql = que[i].second.first , qr = que[i].second.second;
			int t = que[i].first.first , ind = que[i].first.second;
			ans[ind] += get( 0 , qr ) - get( 0 , ql ) + 
				t * 1ll * ( get( 1 , qr ) - get( 1 , ql ) ) ; 
		}
	}

	for( int i = 0 ; i < m ; i++ ) 
		cout << ans[i] << '\n';
}