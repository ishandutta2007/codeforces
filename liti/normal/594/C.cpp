//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000*100 + 100; 
typedef long long ll;
typedef pair<int,int> point;
#define X first
#define Y second
#define left lft
#define right rght
#define up upp
#define down ddn

multiset<point> left,up,right,down; 
point a[maxN];

point que[maxN]; 

inline void add( point a ) { 
	left.insert( { a.X , a.Y } );
	right.insert( { -a.X , a.Y } ) ; 
	up.insert( { -a.Y, a.X } );
	down.insert( { a.Y, a.X } );
}
inline void del( point a ) { 
	left.erase( left.find( { a.X , a.Y } ) );
	right.erase(right.find( { -a.X , a.Y } ) ); 
	up.erase(up.find( { -a.Y, a.X } ) );
	down.erase(down.find( { a.Y, a.X } ) );
}
inline ll cc( int a ) {
	return max(1ll,ll(a+1)/2);
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n,k; cin >> n >> k; 
	for( int i = 0 ; i < n ; i++ ) { 
		int x1,x2,y1,y2; cin >> x1 >> y1 >> x2 >> y2; 
		a[i] = { x1 + x2 , y1 + y2 }; 
		add( a[i] ) ;
	}
	long long ans = 2e18;
	for( int lc = 0 ; lc <= k ; lc++ ) 
		for( int uc = 0 ; uc + lc <= k ; uc++ ) 
			for( int rc = 0 ; rc + uc + lc <= k ; rc++ ) 
				for( int dc = 0; dc + rc + uc + lc <= k ; dc++ ) { 
					int en = 0;
					for( int i = 0 ; i < lc ; i++ ) { 
						auto it = left.begin(); 
						que[en++] = { it->X , it->Y }; 
						del( que[en-1] );
					}
					for( int i = 0 ; i < uc ; i++ ) { 
						auto it = up.begin(); 
						que[en++] = { it->Y , -it->X }; 
						del( que[en-1] );
					}
					for( int i = 0 ; i < rc ; i++ ) { 
						auto it = right.begin(); 
						que[en++] = { -it->X , it->Y }; 
						del( que[en-1] );
					}
					for( int i = 0 ; i < dc ; i++ ) { 
						auto it = down.begin(); 
						que[en++] = { it->Y , it->X }; 
						del( que[en-1] );
					}
					int x1 = left.begin()->X;
					int x2 = -right.begin()->X;
					int y1 = down.begin()->X;
					int y2 = -up.begin()->X;
					ans = min(ans , cc( x2 - x1 ) * cc(y2 - y1) );
					for( int i = 0 ; i < en ; i++ ) 
						add( que[i] );
					
				}
	cout << ans << endl;
}