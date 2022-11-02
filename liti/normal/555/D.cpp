//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define __sz(x) ((int)(x).size())

const int maxN = 2 * 1000 * 100 + 10; 

pair<int,int> a[maxN];
int b[maxN], p[maxN];

int main() { 
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m; 
	cin >> n >> m; 
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i].first; 
		a[i].second = i; 
	}
	sort( a , a + n ) ; 
	for( int i = 0 ; i < n ;i++ ) {
		b[i] = a[i].first;
		p[a[i].second] = i; 
	}
	for( int i = 0 ; i < m ; i++ ) { 
		int x,l; 
		cin >> x >> l; 
		if( n == 1 ) { 
			cout << 1 << '\n';
			continue;
		}
		x--; x = p[x];
		//cerr << "DBG "  << x << endl;
		int d = 1; 
		int left = -1, right = -1;
		while( l >= 0 ) { 
		//cerr << "DBG "  << x << endl;
			if( l == 0 ) break;
			int y;
			if( d == 1 ) { 
				y = upper_bound( b , b + n , b[x] + l ) - b - 1; 
				l -= b[y] - b[x]; 
				right = y; 
				if( right == left ) break;
				if( left != -1 ) { 
					int k = l / ( b[right] - b[left] ) ; 
					l %= ( b[right] - b[left] ) ; 
					if( k % 2 == 1 ) { 
						d *= -1; 
						y = left;
					}
				}
			} else { 
				y = lower_bound( b , b + n , b[x] - l ) - b; 
				l -= b[x] - b[y];
				left = y;
				if( right== left ) break;
				if( right != -1 ) { 
					int k = l / ( b[right] - b[left] ) ; 
					l %= ( b[right] - b[left] ) ; 
					if( k % 2 == 1 ) { 
						d *= -1; 
						y = right;
					}
				}
			}
			d *= -1;
			x = y;
			if( right != -1 && left != -1 && right == left ) break;
		}
		cout << a[x].second + 1 << '\n';
	}
}