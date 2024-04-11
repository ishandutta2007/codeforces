#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {
	ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}
();
template<class T> void _W(const T &x) {
	cout << x;
}
template<class T> void _W(T &x) {
	cout << x;
}
template<class T, class U> void _W(const pair<T, U> &x) {
	_W(x.first);
	putchar(' ');
	_W(x.second);
}
template<class T> void _W(const vector<T> &x) {
	for (auto i = x.begin(); i != x.end(); _W(*i++)) cout << ' ';
}
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) {
	_W(head);
	cout << ", ";
	W(tail...);
}
#ifdef CF_DEBUG
#define debug(...) { cout << "debug : [ "; cout << #__VA_ARGS__; cout << " ] = [ "; W(__VA_ARGS__); cout<<"\b\b ]\n"; }
#else
#define debug(...) (0)
#endif
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
#define all(a) a.begin(),a.end()
#define lb(a, x) distance(begin(a), lower_bound(all(a), (x)))
#define toset(a) (sort(all(a)), a.erase(unique(all(a)), a.end()), a.size())
using pii = pair<int, int>;
const int N = 2e6 + 10, mod = 1e9 + 7, inf = 1e18;

#define x first
#define y second

int qpow(int a, int x) {
	int  ret = 1;
	while (x) {
		if (x & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		x >>= 1;
	}
	return ret;
}
int fac[N], inv[N];

void init() {
	fac[0] = 1;
	for (int i = 1; i < N; i++)
		fac[i] = fac[i - 1] * i % mod;
	inv[N - 1] = qpow(fac[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % mod;
}

int c(int n, int m) {
	if (n < m) return 0;
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

pii a[N];

int n, m;
int dp[N];
void solve() {

	init();
	int h, w;
	cin >> h >> w >> m;
	h--;
	w--;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].x--;
		a[i].y--;
	}
	a[++m] = {h, w};
	sort(a + 1, a + m + 1, [](pii a, pii b) {
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	});

	for (int i = 1; i <= m; i++) {
		dp[i] = c(a[i].x + a[i].y, a[i].x);
		if (!dp[i]) continue;
		for (int j = 1; j < i; j++) {
			dp[i] -= (dp[j] * c(a[i].x - a[j].x + a[i].y - a[j].y, a[i].x - a[j].x)) % mod;
			dp[i] %= mod;
			dp[i] += mod;
			dp[i] %= mod;
		}
	}

	cout << dp[m];

}

signed main() {
	int tt = 1;
	// cin>>tt;
	while (tt--) {
		solve();
	}
}