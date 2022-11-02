//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii; 
typedef long long ll; 
typedef pair<ll,pii> Q; 
int inf = int(1e9 * 2);
pii pinf(inf,inf);
const int maxN = 250 * 1000 + 10; 

Q a[maxN]; 
int p[maxN]; 
ll r[maxN]; 
int que[maxN]; 

pii mn[4*maxN]; 
int n;
inline void build( int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr - xl == 1 ) { 
		mn[ind] = a[xl].second; 
		return; 
	}
	int xm = (xl+xr)/2; 
	build( xl , xm , ind * 2 ); 
	build( xm , xr , ind * 2 + 1 ); 
	mn[ind] = min( mn[ind*2] , mn[ind*2+1] ) ; 
}
inline pii get( int ql , int qr , int xl =0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return pinf;
	if( ql <= xl && xr <= qr ) return mn[ind]; 
	int xm = (xl+xr)/2; 
	return min( get( ql , qr , xl , xm , ind * 2 ) , 
			get( ql , qr , xm , xr , ind * 2 + 1 ) ); 
}
inline void rem( int p , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr - xl == 1 ) { 
		mn[ind] = pinf; 
		return;
	}
	int xm = (xl+xr)/2; 
	if( p < xm ) rem( p , xl , xm , ind * 2 ) ; 
	else rem( p , xm , xr , ind * 2 + 1 ) ; 
	mn[ind] = min( mn[ind*2] , mn[ind*2+1] ) ; 
}


int pl[maxN];
int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int X,Y;
	cin >> X >> Y >> p[0] >> r[0] >> n; 
	r[0] *= r[0]; 
	for( int i = 1 ; i <= n ; i++ ) { 
		int x,y,m; cin >> x >> y >> m >> p[i] >> r[i]; 
		r[i] *= r[i]; 
		x = abs( x - X ) , y = abs( y - Y ); 
		a[i] = Q( x*1ll*x + y*1ll*y , pii( m , i ) ); 
	}
	n++; 
	sort( a + 1 , a + n );
	for( int i = 1 ; i <= n ; i++ ) 
		pl[a[i].second.second] = i; 

	build( 0 , n ); 
	int en = 0;
	que[en++] = 0; 
	for( int i = 0 ; i < en ; i++ ) { 
		int s = que[i]; 
		int x = upper_bound( a + 1 , a + n , Q( r[s] , pii( inf , inf ) ) ) - a; 
		pii ret;
		while( ( ret = get( 1 , x ) , ret.first <= p[s] ) ) { 
//			cout << ret.first << ' ' << ret.second << ' ' << pl[ret.second] << endl;
			rem( pl[ret.second] ); 
			que[en++] = ret.second;
		}
	}
	cout << en - 1 << endl;
}