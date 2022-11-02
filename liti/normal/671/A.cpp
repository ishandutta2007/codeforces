//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef long double ld; 

struct point { 
	int x,y; 
}; 

inline ld dis( point a , point b ) { 
	ld x = (a.x - b.x), y = (a.y - b.y); 
	return sqrt( x*x + y*y ); 
}

const int maxN = 100 * 1000 + 10; 
point p[maxN]; 

ld va[maxN], vb[maxN],mnL[maxN],mnR[maxN];

int main() { 
	point a,b,t;
	cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y; 
	int n; cin >> n;
	ld tot = 0; 
	for( int i = 0 ; i < n ; i++ ) {
		cin >> p[i].x >> p[i].y; 
		tot += 2 * dis( p[i] , t ); 
		va[i] = dis( p[i] , t ) + dis( a, t ) - dis( a , p[i] ); 
		vb[i] = dis( p[i] , t ) + dis( b, t ) - dis( b , p[i] ); 
	}

	tot += dis( a , t ) + dis( b , t ); 
	ld ans = tot - max( dis(a,t) , dis( b,t) ) ; 
	for( int i = 0 ; i < n ; i++ ) 
		mnL[i+1] = max(mnL[i],vb[i]); 
	for( int i = n - 1 ; i > 0 ; i-- ) 
		mnR[i-1] = max(mnR[i],vb[i]); 
	for( int i = 0 ; i < n ; i++ ) { 
		ans = min( ans , tot - va[i] - dis(b,t) ) ; 
		ans = min( ans , tot - vb[i] - dis(a,t)) ; 
		ans = min( ans , tot - va[i] - max( mnL[i] , mnR[i] ) ) ; 
	}
	cout << fixed << setprecision(12) << ans << endl;
}