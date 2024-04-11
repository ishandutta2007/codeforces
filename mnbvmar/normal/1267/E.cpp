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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n, m;
	cin >> n >> m;

	vector<vi> polls(m, vi(n));
	for (auto &row : polls) {
		for (int &x : row) {
			cin >> x;
		}
	}

	int ans = 1e9;
	vi desc;

	for (int other = 0; other < n - 1; ++other) {
		vi diffs(m);
		for (int i = 0; i < m; ++i) {
			diffs[i] = polls[i][other] - polls[i].back();
		}

		int total = accumulate(ALL(diffs), 0);

		vi order(m);
		iota(ALL(order), 0);
		sort(ALL(order), [&](int lhs, int rhs) {
			return diffs[lhs] > diffs[rhs];
		});

		vi cand;
		
		while (total < 0) {
			cand.push_back(order.back() + 1);
			total -= diffs[order.back()];
			order.pop_back();
		}

		if (SZ(cand) < ans) {
			ans = SZ(cand);
			desc = cand;
		}
	}

	cout << ans << "\n";
	for (int v : desc) {
		cout << v << " ";
	}
	cout << "\n";
}