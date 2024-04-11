//FFT algo from KTH ACM Contest Template Library

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = (119 << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
}

typedef vector<ll> vl;
void ntt(ll* x, ll* temp, ll* roots, int N, int skip) {
	if (N == 1) return;
	int n2 = N/2;
	ntt(x     , temp, roots, n2, skip*2);
	ntt(x+skip, temp, roots, n2, skip*2);
	rep(i,0,N) temp[i] = x[i*skip];
	rep(i,0,n2) {
		ll s = temp[2*i], t = temp[2*i+1] * roots[skip*i];
		x[skip*i] = (s + t) % mod; x[skip*(i+n2)] = (s - t) % mod;
	}
}
void ntt(vl& x, bool inv = false) {
	ll e = modpow(root, (mod-1) / sz(x));
	if (inv) e = modpow(e, mod-2);
	vl roots(sz(x), 1), temp = roots;
	rep(i,1,sz(x)) roots[i] = roots[i-1] * e % mod;
	ntt(&x[0], &temp[0], &roots[0], sz(x), 1);
}
vl conv(vl a, vl b) {
	int s = sz(a) + sz(b) - 1; if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
	if (s <= 200) { // (factor 10 optimization for |a|,|b| = 10)
		vl c(s);
		rep(i,0,sz(a)) rep(j,0,sz(b))
			c[i + j] = (c[i + j] + a[i] * b[j]) % mod;
		return c;
	}
	a.resize(n); ntt(a);
	b.resize(n); ntt(b);
	vl c(n); ll d = modpow(n, mod-2);
	rep(i,0,n) c[i] = a[i] * b[i] % mod * d % mod;
	ntt(c, true); c.resize(s); return c;
}

vector<ll> v1, v2, v3;
char str[550000];
int ok[550000];
int bad[550000];
int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		v1.clear();
		v2.clear();
		v3.clear();
		int n;
		scanf("%d%s", &n, str);
		for(int i = 1; i <= n; i++){
			ok[i] = 1;
			bad[i] = 1;
		}
		for(int i = 0; i < n; i++){
			v1.push_back(str[i] == 'V');
		}
		for(int i = 0; i < n; i++){
			v2.push_back(str[n-1-i] == 'K');
		}
		v3 = conv(v1,v2);
		for(int i = 0; i < v3.size(); i++){
			v3[i] %= mod;
			if(v3[i] == 0) continue;
			bad[abs(i-(n-1))] = 0;
			/*cout << "bad " << bad << endl;
			if(bad == 0) continue;
			for(int j = bad; j <= n; j += bad){
				ok[j] = 0;
			}*/
		}
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j += i){
				ok[i] &= bad[j];
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans += ok[i];
		}
		printf("%d\n", ans);
		for(int i = 1; i <= n; i++){
			if(ok[i]){
				printf("%d", i);
				ans--;
				if(ans > 0) printf(" ");
			}
		}
		cout << endl;
	}
}