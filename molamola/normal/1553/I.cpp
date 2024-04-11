#include <bits/stdc++.h>
using namespace std;
 
#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;
 
 
const int mod = 998244353;
 
int pw(int x, int y = mod - 2) {
	int res = 1;
	while(y) {
		if(y & 1) res = (ll) res * x % mod;
		x = (ll) x * x % mod;
		y >>= 1;
	}
	return res;
}
 
void fft(vector<ll> &a, bool inv){
	int n = a.size(), j = 0;
	vector<ll> roots(n/2);
	for(int i=1; i<n; i++){
		int bit = (n >> 1);
		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	int prr = 3;
	int ang = pw(prr, (mod - 1) / n);
	if(inv) ang = pw(ang, mod - 2);
	for(int i=0; i<n/2; i++){
		roots[i] = (i ? (1ll * roots[i-1] * ang % mod) : 1);
	}
	for(int i=2; i<=n; i<<=1){
		int step = n / i;
		for(int j=0; j<n; j+=i){
			for(int k=0; k<i/2; k++){
				ll u = a[j+k], v = (ll)a[j+k+i/2] * roots[step * k] % mod;
				a[j+k] = (u+v>=mod?u+v-mod:u+v);
				a[j+k+i/2] = (u-v<0?u-v+mod:u-v);
			}
		}
	}
	if(inv) for(int i=0; i<n; i++) a[i] = (ll)a[i] * pw(n, mod - 2) % mod;
}
 
vector<ll> multiply(const vector<ll> &v, const vector<ll> &w){
	if(szz(v) == 0 || szz(w) == 0) return {};
	if((ll)v.size() * (ll)w.size() <= 5000) {
		vector <ll> res(szz(v) + szz(w) - 1);
		rep(i, szz(v)) rep(j, szz(w)) res[i + j] = (res[i + j] + v[i] * w[j]) % mod;
		return res;
	}
	vector<ll> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 2; while(n < v.size() + w.size()) n <<= 1;
	fv.resize(n); fw.resize(n);
	fft(fv, 0); fft(fw, 0);
	for(int i=0; i<n; i++) fv[i] = fv[i] * fw[i] % mod;
	fft(fv, 1);
	vector<ll> ret(n);
	for(int i=0; i<n; i++) ret[i] = fv[i];
	while(szz(ret) && ret.back() == 0) ret.pop_back();
	return ret;
}
 
ll F[100010];
 
int n, a[100010];
vector <int> V;
 
struct node {
	vector <ll> P[2][2];
	void init(int x) {
		if(x == 1) P[0][0].pb((mod+1)/2);
		else P[1][1].pb(1);
	}
	int is_one() const {
		int s = 0;
		rep(a, 2) rep(b, 2) s += szz(P[a][b]);
		return s  == 1;
	}
};
 
void add(vector <ll> &a, vector <ll> b) {
	if(szz(a) < szz(b)) a.resize(szz(b));
	rep(i, szz(b)) a[i] = (a[i] + b[i]) % mod;
}
 
node operator+(const node &L, const node &R) {
	node res;
	rep(i, 2) rep(j, 2) {
		rep(k, 2) rep(u, 2) {
			auto mul = multiply(L.P[i][j], R.P[k][u]);
			add(res.P[i][u], mul);
			vector <ll> am(szz(mul) + 1);
			ll mval = 1;
			if(j == 0) mval *= 2;
			if(k == 0) mval *= 2;
			rep(x, szz(mul)) {
				am[x + 1] = mul[x] * mval % mod;
			}
				int pu = (R.is_one() ? 1 : u);
				int pi = (L.is_one() ? 1 : i);
			add(res.P[pi][pu], am);
		}
	}
	return res;
}
 
node T[1<<18];
 
void Calc(int rt, int l, int r) {
	if(l == r) {
		T[rt].init(V[l]);
		return;
	}
	int m = (l + r) >> 1;
	Calc(rt * 2, l, m);
	Calc(rt * 2 + 1, m + 1, r);
	T[rt] = T[rt * 2] + T[rt * 2 + 1];
}
 
void solve() {
	F[0] = 1;
	for(int i=1;i<100010;i++) F[i] = i * F[i-1] % mod;
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", a + i);
	}
	for(int i=1;i<=n;) {
		if(a[i] == 1) {
			V.pb(1);
			i += 1;
		}
		else {
			int j = i + a[i] - 1;
			if(j > n) {
				puts("0");
				return;
			}
			for(int k=i;k<=j;k++) {
				if(a[k] != a[i]) {
					puts("0");
					return;
				}
			}
			V.pb(2);
			i = j + 1;
		}
	}
	int m = szz(V);
	Calc(1, 0, m - 1);
	auto ans = T[1];
	ll res = 0;
	for(int i=0;i<m;i++) {
		ll val = 1;
		if(i & 1) val = mod - 1;
		ll s = 0;
		rep(a, 2) rep(b, 2) {
			if(i < szz(ans.P[a][b])) s = (s + ans.P[a][b][i]) % mod;
		}
		val = val * s % mod;
		int nt = m - i;
		val = val * F[nt] % mod;
		val = val * pw(2, nt) % mod;
		res = (res + val) % mod;
	}
	printf("%lld\n", res);
}
 
int main() {
	int TC = 1; //scanf("%d", &TC);
	rep(tt, TC) {
		solve();
	}
	return 0;
}