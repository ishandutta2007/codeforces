//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 2 * 1000 * 10000 + 100; 

int a[maxN]; 
int b[maxN]; 
int nex[maxN]; 

int n;
inline int get( int x ) { 
	if( x == n ) return n;
	if( a[x] == 0 ) return nex[x] = get( nex[x] ); 
	return x; 
}


int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	cin >>n;
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i]; 
		nex[i] = i + 1; 
		b[i] = a[i]; 
	}
	int q; cin >> q; 
	for( int i = 0 ; i < q ; i++ ) { 
		int t; cin >> t; 
		if( t == 1 ) { 
			int x, v; cin >> x >> v; 
			x--; 
			while( v && x != n ) { 
				int k = min( v , a[x] ); 
				v -= k; 
				a[x] -= k;
				x = get(x);
			}
		} else { 
			int x; cin >> x; x--; 
			cout << b[x] - a[x] << '\n'; 
		}
	}
}