#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin() ,(x).end()
#define st first
#define nd second
using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pll = pair<ll, ll>;

template <typename TH> void _dbg(const char *s, TH h) {
	cerr << s << "=" << h << "\n";
}
template <typename TH, typename ...TA> void _dbg(const char *s, TH h, TA... a) {
	while (*s != ',') cerr << *s++;
	cerr << "=" << h << ",";
	_dbg(s+1, a...);
}

template <typename T> ostream &operator<<(ostream &os, vector<T> V) {
	os <<"[";
	for (auto v:V) os << v << ",";
	return os << "]";
}
template <typename L, typename R> ostream &operator<<(ostream &os, pair<L,R> V) {
	return os << "(" << V.st << "," << V.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

void Test() {
	int n;
	cin >> n;
	vi cnts(n + 1);
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		++cnts[v];
	}

	vi real_cnts;
	for (int x : cnts) {
		if (x) { real_cnts.push_back(x); }
	}
	sort(ALL(real_cnts));
	const int max_s = real_cnts[0] + 1;

	ll ans = 1e9;

	for (int s = 2; s <= max_s; ++s) {
		ll cand = 0;
		for (int x : real_cnts) {
			const int need_scr = (x + s - 1) / s;
			const int min_x = need_scr * (s - 1);
			if (min_x > x) {
				cand = 1e9;
			} else {
				cand += need_scr;
			}
		}
		ans = min(ans, cand);
	}

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int t;
	cin >> t;
	while (t--) {
		Test();
	}
}