//In the name of Allah  He's With us
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
typedef pair<int,int> pii;

const int maxN = 1000 * 100 + 100; 
pii a[maxN];
int p[maxN];

ll sum[4*maxN] , inc[4*maxN];

int n; 
inline void sVal( int p , int v , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr - xl == 1 ) { 
		sum[ind] = v;
		return;
	}
	int xm = (xl+xr)>>1; 
	if( p < xm ) sVal( p , v , xl , xm , ind * 2 ) ; 
	else sVal( p , v , xm , xr , ind * 2 + 1 ) ; 
	sum[ind] = sum[ind*2] + sum[ind*2+1]; 
	inc[ind] = inc[ind*2] + inc[ind*2+1] + ll(xm-xl)*sum[ind*2+1];
}
inline ll gVal( int ql , int qr , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return 0; 
	if( ql <= xl && xr <= qr ) { 
		int sz = qr - ql;
		// ( 1 - sz ) a[ql] + ( 3 - sz ) a[ql+1] + ... 
		// - sz * (sum) + 
		// 1 a[ql] + 3 a[ql+1] + .... 
		ll ret1 = -sz * sum[ind];
		ll ret2 = inc[ind] + (xl - ql) * sum[ind];
		ll ret3 = sum[ind];
		return ret3 + 2*ret2 + ret1;
	}
	int xm = (xl+xr)>>1;
	return gVal( ql , qr , xl , xm , ind * 2 ) + 
		gVal( ql , qr , xm , xr , ind * 2 + 1 ) ; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;

	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i].first;
		a[i].second = i;
	}
	sort( a , a + n ) ; 
	for( int i = 0 ; i < n ; i++ ) { 
		p[a[i].second] = i; 
		sVal( i , a[i].first ); 
	}
	int m;
	cin >> m;
	for( int i = 0 ; i < m ; i++ ) {
		int t; cin >> t;
		if( t == 1 ) { 
			int x , d; cin >> x >> d;
			x--; x = p[x];
			if( d < 0 ) {
				a[x].first += d;
				while( x && a[x-1].first > a[x].first ) {
					swap( a[x-1] , a[x] ) ; 
					sVal( x , a[x].first );
					p[a[x].second] = x; 
					x--;
				}
				sVal( x , a[x].first ) ; 
				p[a[x].second] = x;
			} else { 
				a[x].first += d;
				while( x < n - 1 && a[x+1].first < a[x].first ) { 
					swap( a[x] , a[x+1] ) ; 
					sVal( x , a[x].first ) ; 
					p[a[x].second] = x; 
					x++;
				}
				sVal( x , a[x].first ) ; 
				p[a[x].second] = x;
			}
		} else { 
			int l,r; cin >> l >> r;
			l = lower_bound( a , a + n , make_pair(l,0) ) - a;
			r = upper_bound( a , a + n , make_pair(r,n) ) - a; 
			cout << gVal( l , r ) << '\n';
		}
	}
}