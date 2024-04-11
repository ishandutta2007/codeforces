//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii; 
const int mod = 1e9 + 7; 
const int maxN = 1000 * 1000 +  10;

inline int sum(int a, int b) { 
	int c = a+b; 
	if( c >= mod ) c -= mod; 
	return c;
}

int bpow(int a, int b) { 
	int r = 1; 
	for( ; b ; b /= 2 ) { 
		if( b & 1 ) 
			r = 1ll * r * a % mod;
		a = 1ll * a * a % mod; 
	}
	return r;
}

int main() {

	int x, y; 
	cin >> x >> y; 
	if( y % x != 0 ) { 
		cout << 0 << endl;
		return 0;
	}
	
	int n = y / x;
	int tmp = n; 

	vector<int> pr;
	for(int i = 2 ; i * i <= tmp; i++) 
		if( tmp % i == 0 ) { 
			pr.push_back(i);
			while( tmp % i == 0 ) 
				tmp /= i; 
		}

	if( tmp > 1 ) 
		pr.push_back( tmp );

	int k = pr.size(); 
	int ans = 0;
	for( int mask = 0; mask < (1<<k) ; mask++ ) { 
		int z = 1; 
		for( int i = 0 ; i < k ; i++ ) 
			if( (mask>>i) & 1 ) 
				z *= pr[i]; 
		int tmp = bpow(2, (n / z)-1);
		if( __builtin_popcount(mask) % 2 == 0 ) 
			ans = sum(ans, tmp);
		else
			ans = sum(ans, mod - tmp);
	}
	cout << ans << endl;

	return 0;
}