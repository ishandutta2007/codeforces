#include <bits/stdc++.h>
using namespace std;
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const ll mod = 998244353; // faster if const
ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
}
 
vector<ll> BerlekampMassey(vector<ll> s) {
	int n = sz(s), L = 0, m = 0;
	vector<ll> C(n), B(n), T;
	C[0] = B[0] = 1;
 
	ll b = 1;
	rep(i,0,n) { ++m;
		ll d = s[i] % mod;
		rep(j,1,L+1) d = (d + C[j] * s[i - j]) % mod;
		if (!d) continue;
		T = C; ll coef = d * modpow(b, mod-2) % mod;
		rep(j,m,n) C[j] = (C[j] - coef * B[j - m]) % mod;
		if (2 * L > i) continue;
		L = i + 1 - L; B = T; b = d; m = 0;
	}
 
	C.resize(L + 1); C.erase(C.begin());
	trav(x, C) x = (mod - x) % mod;
	return C;
}
 
typedef vector<ll> Poly;
ll linearRec(Poly S, Poly tr, ll k) { /// start-hash
	int n = sz(S);
 
	auto combine = [&](Poly a, Poly b) {
		Poly res(n * 2 + 1);
		rep(i,0,n+1) rep(j,0,n+1)
			res[i + j] = (res[i + j] + a[i] * b[j]) % mod;
		for (int i = 2 * n; i > n; --i) rep(j,0,n)
			res[i - 1 - j] = (res[i - 1 - j] + res[i] * tr[j]) % mod;
		res.resize(n + 1);
		return res;
	};
 
	Poly pol(n + 1), e(pol);
	pol[0] = e[1] = 1;
 
	for (++k; k; k /= 2) {
		if (k % 2) pol = combine(pol, e);
		e = combine(e, e);
	}
 
	ll res = 0;
	rep(i,0,n) res = (res + pol[i + 1] * S[i]) % mod;
	return res;
} /// end-hash
 
 
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	int m;
	cin >> n >> m;
	if(n < 3){
		cout << 0 << '\n';
		return 0;
	}
	int a[5]; int b[5];
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	const int R = 700;
	vector<ll> vals(R+1, 0);
	int f[5];
	for(f[0] = 0; f[0] <= R; f[0]++){
		for(f[1] = 0; f[1] <= R; f[1]++){
			int r1 = -a[0] * f[0] - a[1] * f[1];
			int r2 = -b[0] * f[0] - b[1] * f[1];
			for(f[2] = 0; f[2] <= R; f[2]++){
				int cxs = r1;
				int cys = r2;
				r1 -= a[2];
				r2 -= b[2];
				if(n == 4){
					if(a[3]){
						f[3] = cxs / a[3];
					} else if(b[3]){
						f[3] = cys / b[3];
					} else assert(false);
					if(f[3] < 0) continue;
					cxs -= a[3] * f[3];
					cys -= b[3] * f[3];
				} else if(n == 5){
					int d = a[3] * b[4] - a[4] * b[3];
					f[3] = (cxs * b[4] - a[4] * cys) / d;
					if(f[3] < 0) continue;
					f[4] = (a[3] * cys - cxs * b[3]) / d;
					if(f[4] < 0) continue;
					cxs -= a[3] * f[3] + a[4] * f[4];
					cys -= b[3] * f[3] + b[4] * f[4];
				}
				if(cxs != 0 || cys != 0) continue;
				int xpsum = 0, ypsum = 0;
				for(int i = 0; i < n; i++){
					if(a[i] >= 0) xpsum += a[i] * f[i];
					if(b[i] >= 0) ypsum += b[i] * f[i];
				}
				if(xpsum > R || ypsum > R) continue;
				vals[max(xpsum, ypsum)]++;
			}
		}
	}
	for(int i = 1; i <= R; i++){
		vals[i] += vals[i-1];
	}
	vector<ll> rec = BerlekampMassey(vals);
	vals.resize(rec.size());
	ll res = linearRec(vals, rec, m);
	res = (res + mod - 1) % mod;
	cout << res << '\n';
}