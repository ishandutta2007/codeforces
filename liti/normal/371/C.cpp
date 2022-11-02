//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int main() { 
	string k; 
	cin >> k; 
	int b,ss,c = ss = b =0; 
	for( auto x : k ) {
		if( x == 'B' ) b++; 
		if( x == 'C' ) c++; 
		if( x == 'S' ) ss++; 
	}
	int nb,ns,nc; cin >> nb >> ns >> nc; 
	int pb,ps,pc; cin >> pb >> ps >> pc; 
	ll n; cin >> n; 
	ll s = 0 , e = 2e12; 
	while( e - s > 1 ) { 
		ll m = (s+e)/2; 
		ll cost = max( 1ll * b * m - nb , 0ll ) * pb + 
			max( 1ll * ss * m - ns , 0ll ) * ps + 
			max( 1ll * c * m - nc , 0ll ) * pc; 
		if( cost <= n ) s = m; 
		else e = m;
	}
	cout << s << endl;
}