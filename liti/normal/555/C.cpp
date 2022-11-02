//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define __sz(x) ((int)(x).size())

const int maxN = 2 * 1000 * 100 + 10; 
vector<int> X , Y; 
struct Que { 
	int x , y ; char ch; 
};

Que a[maxN];
typedef int Seg[4*maxN];
Seg seg[2];

int gg( int p , Seg seg , int xl , int xr , int ind = 1 ) { 
	if( xr - xl == 1 ) 
		return seg[ind];
	int xm = (xl+xr)>>1;
	seg[ind*2] = max( seg[ind*2] , seg[ind] ) ; 
	seg[ind*2+1] = max( seg[ind*2+1] , seg[ind] ) ; 
	if( p < xm ) 
		return gg( p , seg , xl , xm , ind * 2 ) ; 
	else
		return gg( p , seg , xm , xr , ind * 2 + 1 ) ; 
}
void ss( int ql , int qr , int v , Seg seg , int xl , int xr , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) 
		return; 
	if( ql <= xl && xr <= qr ) { 
		seg[ind] = max( seg[ind] , v ) ; 
		return;
	}
	int xm = (xl+xr)>>1;
	seg[ind*2] = max( seg[ind*2] , seg[ind] ) ; 
	seg[ind*2+1] = max( seg[ind*2+1] , seg[ind] ) ; 
	ss( ql , qr , v , seg , xl , xm , ind * 2 ) ; 
	ss( ql , qr , v , seg , xm , xr , ind * 2 + 1 ) ; 
}

int usedX[maxN], usedY[maxN];

int main() { 
	int n, m; 
	cin >> n >> m; 
	for( int i = 0 ; i < m ; i++ ) { 
		cin >> a[i].y >> a[i].x >> a[i].ch; 
		X.push_back( a[i].x ) ; 
		Y.push_back( a[i].y ); 
	}
	sort( X.begin() , X.end() ) ; 
	X.resize( unique( X.begin() , X.end() ) - X.begin() ) ; 
	sort( Y.begin() , Y.end() ) ; 
	Y.resize( unique( Y.begin() , Y.end() ) - Y.begin() ) ; 

	for( int i = 0 ; i < m ; i++ ) { 
		int x = lower_bound( X.begin() , X.end() , a[i].x ) - X.begin(); 
		int y = lower_bound( Y.begin() , Y.end() , a[i].y ) - Y.begin() ; 
		if( a[i].ch == 'U' ) {	
			if( usedY[y] ) { 
				cout << 0 << '\n';
				continue;
			}
			usedY[y] = true;
			int v = gg( y , seg[1] , 0 , Y.size() ) ; 
			int k = lower_bound( X.begin() , X.end() , v ) - X.begin() ; 
//			cerr << v << ' ' << a[i].x << endl;
			cout << a[i].x - v << '\n';
			ss( k , x + 1 , a[i].y , seg[0] , 0 , X.size() ) ; 
		} else { 
			if( usedX[x] ) { 
				cout << 0 << '\n';
				continue;
			}
			usedX[x] = true;
			int v = gg( x , seg[0] , 0 , X.size() ) ; 
			int k = lower_bound( Y.begin() , Y.end() , v ) - Y.begin() ; 
//			cerr << v << ' ' << a[i].y << endl;
			cout << a[i].y - v << '\n';
			ss( k , y + 1 , a[i].x , seg[1] , 0 , Y.size() ) ; 
		}
	}
}