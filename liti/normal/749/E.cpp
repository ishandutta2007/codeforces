//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 100 * 1000 + 10; 
typedef long long ll; 
typedef long double ld; 

ll fen[maxN], fen2[maxN]; 
void add( int x , int v ) { 
	x++; 
	for( ; x < maxN ; x += x & -x ) 
		fen[x] += v; 
}

ll get( int x ) { 
	x++; 
	ll ret = 0; 
	for( ; x ; x -= x & -x ) 
		ret += fen[x]; 
	return ret; 
}
void add2( int x , int v ) { 
	x++; 
	for( ; x < maxN ; x += x & -x ) 
		fen2[x] += v; 
}

ll get2( int x ) { 
	x++; 
	ll ret = 0; 
	for( ; x ; x -= x & -x ) 
		ret += fen2[x]; 
	return ret; 
}

int main() { 
	cout << fixed << setprecision(15) ; 
	int n; cin >> n; 
	ll tot = n * 1ll * (n+1) / 2; 

	ld ans = 0; 
	ll sum = 0; 
	for( int i = 0 ; i < n ; i++ ) { 
		int x; cin >> x; 

		ll bad = get(x);
		ll v = sum - bad; 
		ans += ( i - get2(x) )  - (v * (n-i) / ld(tot) / 2); 
		ans += bad * (n-i) / ld(tot) / 2; 

		add( x , i + 1 ); 
		add2( x , 1 ); 
		sum += i + 1; 
	}

	cout << ans << endl;
}