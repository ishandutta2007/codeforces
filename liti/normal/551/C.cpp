//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000*100 + 100; 
int a[maxN];
int b[maxN];
int n,m; 
bool check( ll v ) { 
	copy( a , a + n , b ) ; 
	ll mvt = 0; 
	ll st = 0; 
	ll cnt = 0; 
	for( int i = 0 ; i < n ; i++ ) { 
		mvt++; 
		if( st + mvt == v && st > 0 ) {
			cnt++; 
			st = 0;
		}
		if( a[i] == 0 ) continue;
		if( mvt >= v ) return false;
		ll tmp = min( v - mvt - st , 1ll*b[i] ) ; 
		b[i] -= tmp;  
		st += tmp; 
		if( st + mvt == v ) { 
			cnt++; 
			mvt--;
			st = 0; 
			i--; 
		}
	}
//	if( v == 5 ) 
//		cout << cnt << ' ' << st << endl;
	if( cnt < m || (cnt == m && st == 0 ) ) 
		return true;
	return false;
}

int main() {
	 cin >> n >> m; 
	 for( int i = 0 ; i < n ; i++ )
		 cin >> a[i]; 
	 ll s = 0  , e = 1e16 + 10; 
	 while( e - s > 1 ) { 
		 ll m = (s+e)>>1; 
		 if( check(m) ) 
			 e = m;
		 else
			 s = m; 
	 }
//	 cout << check(5) << endl;
	 cout << e << endl;
}