/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*100 + 10; 
const int maxL = maxN;
long long a[maxN];
pair<int,int> nex[maxN];

struct Node { 
	Node( ) { 
		mx = id = 0;
		_l = NULL;
		_r = NULL;
	}
	void set( int p , int val , int idx , int xl = 0 , int xr = maxL ) { 
		if( p == xl && p == xr - 1 ) {
//			cout << "DADA " << p << ' ' << val << ' ' << idx << endl;
			if( val > mx ) { 
				mx = val;
				id = idx;
			}
//			cout << "HA HA " << mx << ' ' << val << endl;
			return;
		}
		int xm = (xl + xr) / 2 ; 
		if( p < xm ) { 
			l()->set( p , val , idx , xl , xm ) ; 
			if( l()->mx > mx ) { 
				mx = l()->mx ; 
				id = l()->id;
			}
		} else { 
			r()->set( p , val , idx , xm , xr ) ; 
			if( r()->mx > mx ) { 
				mx = r()->mx ; 
				id = r()->id;
			}
		}
//		cerr << xl << ' ' << xr << ' ' << mx << ' ' << r()->mx << ' ' << l()->mx << endl;
	}
	pair<int,int> get( int ql , int qr, int xl = 0 , int xr = maxL ) { 
		if( xl == ql && qr == xr ) 
			return {mx,id};
		int xm = (xl + xr) / 2 ;
		pair<int,int> ret = {0,0};
		if( ql < xm ) 
			ret = l()->get( ql , min( xm , qr ) , xl , xm ) ; 
		if( qr > xm ) 
			ret = max( ret , r()->get( max( ql , xm ) , qr , xm , xr ) ) ;
		return ret;
	}
	Node* l() { 
		if( _l == NULL ) 
			_l = new Node() ; 
		return _l;
	}
	Node* r() { 
		if( _r == NULL ) 
			_r = new Node( ) ; 
		return _r;
	}


	int mx, id;
	Node *_l , *_r ; 
}root;

long long b[maxN];
int main() { 
	ios::sync_with_stdio(false);
	memset( nex, -1 , sizeof nex ); 
	int n , d;
	cin >> n >> d;

	for( int i = 0 ; i < n ; i++ ) 
		cin>> a[i];
	copy( a , a + n , b ) ; 
	sort( b , b + n ) ;
	int bn = unique( b, b + n ) - b;

	root.set( lower_bound( b , b + bn ,a[n-1]) - b , 1, n - 1  ) ; 

	pair<int,int> mx = {1, n-1} ; 
	for( int i = n - 2 ; i>= 0 ; i-- ) {
		int poo = lower_bound( b , b + bn , a[i] + d ) - b;
		int hoo = upper_bound( b , b + bn , a[i] - d ) - b;
		pair<int,int>  x = max( ( poo != bn ? root.get( poo , maxL ) : make_pair(0,0)  ) ,
				( hoo != 0 ? root.get(  0 , hoo )  : make_pair(0,0) ) ) ; 
		x.first ++;
		int hoy = lower_bound( b, b + bn, a[i]) - b;
		root.set( hoy , x.first , i) ; 
		nex[i] = x;
		if( nex[i].second == 0 ) 
			nex[i].second = -1;
		mx = max( mx, {nex[i].first,i} ) ; 
	}

	cout << mx.first << endl;
	int idx = mx.second;
	while( idx != -1 ) {
		cout << idx + 1 << ' ';
		idx = nex[idx].second ;
	}
	cout << endl;
}