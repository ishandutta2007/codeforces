/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*1000 + 10;

int a[maxN], b[maxN];
vector<int> c[maxN], a1, a2;

int main() { 
	int n;
	cin >> n;

	for( int i = 1 ; i <= n ; i++ )  { 
		cin >> a[i] >> b[i];
		c[a[i]].push_back( b[i] ) ; 
		c[b[i]].push_back( a[i] ) ; 
	}

	for( int i = 1 ; i <= n ; i++ ) { 
		if( a[i] == 0 ) { 
			int x= b[i];
			int y = 0;
			a1.push_back( x ) ;
			while( x != 0 && sz( c[x] ) >= 2 ) {
//				cout << y << ' ' << x << ' ' << c[x][0] << ' ' << c[x][1] << endl;
				int tmp = x;
				if( c[x][0] != y )  
					x = c[x][0];
				else
					x = c[x][1];
				y = tmp;

				if( x != 0 )
					a1.push_back( x ) ;
			}
		}
		if( b[i] == 0 ) { 
			int x = a[i];
			int y = 0;
			a2.push_back( x ) ;
			while( x != 0 && sz(c[x]) >= 2 ) {
				int tmp = x;
				if( c[x][0] != y )  
					x = c[x][0];
				else
					x = c[x][1];
				y = tmp;

				if( x != 0 )
					a2.push_back( x ) ;
			}
		}
	}

	if( n & 1 ) { 
		a2.clear();
		for( int i =1 ; i <= n ; i++ ) 
			if( sz( c[b[i]] ) == 1 )  { 
				int x = b[i];
				int y = 0;
				a2.push_back( x ) ;
				while( x != 0 && ( x == b[i] || sz(c[x]) >= 2 ) ) {
		//			cout << x << endl;
					int tmp = x;
					if( c[x][0] != y )  
						x = c[x][0];
					else
						x = c[x][1];
					y = tmp;

					if( x != 0 )
						a2.push_back( x ) ;
		//			cout << x << endl;
				}
				break;
			}

	}

	//cout << sz(a1) << ' ' << sz( a2) << endl;
	for( int i = 0 ; i < n ; i++ ) 
		if( i & 1 ) { 
			assert( i / 2 < sz(a1) ) ;
			cout << a1[i/2] << ' ';
		} else { 
			assert( sz(a2) - (i/2) - 1 >= 0 ) ;
			cout << a2[ sz(a2) - (i/2) - 1 ] << ' ' ;
		}

	cout << endl;
}