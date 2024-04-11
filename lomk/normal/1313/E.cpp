/*input
5 5
azbcd
xlulx
azlul
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cout << "[" << #x << "] ="; _print(x);}
void _print() {cout << endl;}
template<typename T, typename... Ts> void _print(const T& value, const Ts&... values) {cout << ' ' << value; _print(values...);}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value; _print(values...);}
#define int long long
// change cout to cerr for debug in crash
// for struct, can write print operator to use print() (even with SegTree)
#ifndef UncleGrandpa
const int N = 1e6 + 5;
#else
const int N = 1e2 + 5;
#endif

// z[i] =  di xu con di nht bt u t v tr i m trng vi on u ca v[]
vector<int> zfunc(string s) {
	int n = (int) s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

class ITrangeSum {
public:
#define mid ((l+r)/2)
	int n, f[4 * N], lazy[4 * N];
	void dolazy(int k, int l, int r) {
		if (lazy[k] == 0) return;
		f[k] = (f[k] + 1LL * lazy[k] * (r - l + 1));
		if (l != r) {
			lazy[k * 2] = (lazy[k * 2] + lazy[k]);
			lazy[k * 2 + 1] = (lazy[k * 2 + 1] + lazy[k]);
		}
		lazy[k] = 0;
	}
	void update(int k, int l, int r, int L, int R, int val) {
		dolazy(k, l, r);
		if (r < L || R < l) return;
		if (L <= l && r <= R) {
			lazy[k] = (lazy[k] + val); dolazy(k, l, r);
			return;
		}
		update(k * 2, l, mid, L, R, val); update(k * 2 + 1, mid + 1, r, L, R, val);
		f[k] = (f[k * 2] + f[k * 2 + 1]);
	}
	int get(int k, int l, int r, int L, int R) {
		dolazy(k, l, r);
		if (r < L || R < l || l > r) return 0;
		if (L <= l && r <= R) return f[k];
		return (get(k * 2, l, mid, L, R) + get(k * 2 + 1, mid + 1, r, L, R));
	}
	void init(int k, int l, int r) {
		f[k] = lazy[k] = 0; if (l == r)return;
		init(k * 2, l, mid); init(k * 2 + 1, mid + 1, r);
	}
	void init(int _n) {n = _n; init(1, 0, n + 1);}
	int get(int l, int r) {return get(1, 0, n + 1, l, r);};
	void update(int l, int r, int val) {update(1, 0, n + 1, l, r, val);};
#undef mid
} ITmark, ITsum;

ostream &operator<<(ostream &os, ITrangeSum a) {
	loop(i, 0, a.n - 1) os << a.get(i, i) << sp;
	return os;
}

int n, m;
string a, b, s;
vector<int> pre, suf;
vector<int> preal[N], sufal[N];

void prep() {
	auto rec = zfunc(s + "!" + a);
	pre.insert(pre.end(), rec.begin() + m + 1, rec.end());
	reverse(s.begin(), s.end()); reverse(b.begin(), b.end());
	rec = zfunc(s + "!" + b);
	suf.insert(suf.end(), rec.begin() + m + 1, rec.end());
	reverse(suf.begin(), suf.end());
	for (auto &it : pre) it = min(it, m - 1);
	for (auto &it : suf) it = min(it, m - 1);
	loop(i, 0, n - 1) preal[pre[i]].push_back(i);
	loop(i, 0, n - 1) sufal[suf[i]].push_back(i);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	cin >> a >> b >> s;
	prep();
	ITmark.init(n); ITsum.init(n);
	loop(i, 0, n - 1) if (suf[i]) ITmark.update(i, i, 1), ITsum.update(i, i, suf[i]);
	int ans = 0;
	rloop(i, m - 1, 1) {
		for (auto it : preal[i]) {
			int l = it, r = min(n - 1, it + m - 2);
			ans += ITsum.get(l, r) - ITmark.get(l, r) * (m - i - 1);
		}
		for (auto it : sufal[m - i]) ITmark.update(it, it, -1), ITsum.update(it, it, -m + i);
		// print("rem", m - i);
	}
	cout << ans << endl;
}