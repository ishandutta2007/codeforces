//In the name of Allah
#include <iostream>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int mul(int a, int b) { 
	return 1ll * a * b % mod;
}

int sum(int a, int b) { 
	int c = a + b;
	if( c >= mod )
		c -= mod;
	return c;
}

int bpow(int a, int b) { 
	int r = 1; 
	for(; b ; b /= 2) { 
		if( b % 2 ) 
			r = mul(r, a);
		a = mul(a,a);
	}
	return r;
}

const int N = 2000*1000 + 100;

int f[N], finv[N];
int tav[N];

int choose(int n, int r) { 
	if( r < 0 || r > n ) return 0; 
	return mul( f[n] , mul( finv[n-r], finv[r] ) );
}

int main() { 
	f[0] = finv[0] = 1;
	for(int i = 1; i < N; i++) {
		f[i] = mul(i, f[i-1]);
		finv[i] = bpow(f[i], mod-2);
	}

	int n, m, x;
	cin >> n >> m >> x >> x; 

	tav[0] = 1;
	for(int i = 1; i < n + 3; i++)
		tav[i] = mul(m, tav[i-1]);

	int ans = 0; 

	for(int l = 1; l <= min(n-1, m); l++) {
		int v = m - l; 
		int cnt = choose(v+l-1, l-1);
		int scnt = mul( f[n-2] , finv[n-2-l+1] );
		int tcnt = mul( f[n-1] , finv[l] );
		if(l < n-1)
			tcnt = mul(l+1, bpow(n,n-l-2));
		
		int zcnt = tav[n-1-l];
		//cerr << l <<  " " << cnt << " " << scnt << " " << tcnt << " " << zcnt << endl;
		ans = sum(ans, mul(mul(cnt, zcnt), mul(scnt, tcnt)));
	}
	cout << ans << endl;
}