//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

typedef pair<ll,ll> pii;
map<ll,pii> dp; 

pii solve( ll n ) { 
	if( n == 0 ) return pii( 0 , 0 ) ; 
	if( dp.count(n) ) return dp[n]; 
	ll s = 0 , e = 1000 * 100 + 100;
	while( e - s > 1 ) { 
		ll m = (s+e)/2; 
		if( m * m * m <= n ) 
			s = m;
		else
			e = m; 
	}

	ll num = s * s * s;
	ll x = n / num;
	auto r1 = solve( n - x * num ); 
	r1.first+= x, r1.second += x * num; 
	auto r2 = solve( num - 1 ); 
	r2.first += x - 1; 
	r2.second += ( x - 1 ) * num;
	return dp[n] = max(r1,r2); 
} 

int main() { 
	ll n; cin >> n; 
	auto ret = solve(n); 
	cout << ret.first << ' ' << ret.second << endl; 
}