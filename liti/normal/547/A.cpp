//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000*1000 + 10; 
int t1[maxN] , t2[maxN];
int main() { 
	int m, h1,a1, x1,y1 , h2,a2,x2,y2;
	cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
	// hi = ( x1 h_{i-1} + y1 ) % m
	memset( t1 , -1 , sizeof t1 ) ; 

	int x = h1; 
	int c1 = 0;
	int z1 = -1;
	while( t1[x] == -1 ) { 
		t1[x] = c1++; 
		if( x == a1 ) z1 = t1[x]; 
		x = ( x1 * 1ll * x + y1 ) % m;
	}
	int y = x;

	memset( t2 , -1 , sizeof t2 ) ; 
	x = h2;
	int c2 = 0;
	int z2 = -1;
	while( t2[x] == -1 ) { 
		t2[x] = c2++; 
		if( x == a2 ) z2 = t2[x]; 
		x = ( x2 * 1ll * x + y2 ) % m;
	}

	if( z1 == -1 || z2 == -1 ) {
		cout << -1 << endl;
		return 0;
	}
	if( z1 == z2 ) {
		cout << z1 << endl;
		return 0;
	}

	int cyc1 = c1 - t1[y] , cyc2 = c2 - t2[x];
	// z1 + cyc1 * k = z2 + cyc2 * k'
	// cyc1 * k - cyc2 * k' = z2 - z1
	// A x + B y = C
	ll ans , tmp = ans = 1e16;
	for( int i = 0 ; i < maxN ; i++ ) { 
		ll tt = z1 + cyc1 *1ll* i ;
		if( i > 0 && z1 < t1[y] ) continue;
		ll p = (tt - z2) ; 
		if( p < 0 || p % cyc2 != 0 ) continue;
		p /= cyc2;
		if( p > 0 && z2 < t2[x] ) continue;
		ans = min(ans,tt);
	}
	cout << (ans==tmp?-1:ans) << endl;
}