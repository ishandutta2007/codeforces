//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 5 * 1000 * 100 + 100; 
const int SQ = 700; 
typedef long long ll; 
typedef pair<ll,int> pii; 

ll toadd[maxN/SQ]; 
pii a[maxN]; 
int n; 

inline void relax(int xl, int xr) { 
	sort( a + xl , a + xr ); 
}

void build() { 
	for( int xl = 0 ; xl < n ; xl += SQ ) { 
		int xr = min( xl + SQ , n ); 
		relax( xl , xr ); 
	}
}

inline void change( int ql, int qr, int qv ) { 
	for( int xl = 0 ; xl < n ; xl += SQ ) { 
		int xr = min( xl + SQ , n ); 
		if( ql <= xl && xr <= qr ) 
			toadd[xl/SQ] += qv; 
		else { 
			int L = max(ql,xl), R = min(qr,xr); 
			if( L >= R ) continue;
			for( int i = xl ; i < xr ; i++ ) 
				if( L <= a[i].second && a[i].second < R ) 
					a[i].first += qv; 
			relax( xl , xr ); 
		}
	}
}

inline int get( int y ) { 
	int L = -1 , R;
	for( int xl = 0 ; xl < n ; xl += SQ ) { 
		int xr = min( xl + SQ , n ); 
		int id = upper_bound( a + xl , a + xr ,
				pii(y - toadd[xl/SQ],n) ) - a; 
		if( id-- != xl && a[id].first + toadd[xl/SQ] == y ) { 
			R = a[id].second; 
			if( L == -1 ) 
				L = lower_bound( a + xl , a + xr , 
						pii(y - toadd[xl/SQ],0) )->second; 
		}
	}
	if( L == -1 ) return -1; 
	return R - L; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 

	int q; cin >> n >> q; 

	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i].first; 
		a[i].second = i;
	}

	build(); 

	for( int i = 0 ; i < q ; i++ ) { 
		int t; cin >> t; 
		if( t == 1 ) { 
			int ql, qr, qv; 
			cin >> ql >> qr >> qv; 
			ql--; 
			change( ql , qr , qv ); 
		} else { 
			int y; 
			cin >> y; 
			cout << get( y ) << '\n'; 
		}
	}
}