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

	int n, m, ka, kb;
	cin >> n >> m >> ka >> kb;
	if (ka >= m || kb >= n) {
		cout << "No\n";
		return 0;
	}

	vi A(ka), B(kb);
	for (int &x : A) { cin >> x; }
	for (int &x : B) { cin >> x; }

	while (SZ(A) < m-1) { A.push_back(1); }
	while (SZ(B) < n-1) { B.push_back(n + 1); }

	map<int, int> rem;
	for (int x : A) { ++rem[x]; }
	for (int x : B) { ++rem[x]; }

	int aptr = 0, bptr = 0;
	set<int> leaves;
	for (int i = 1; i <= n + m; ++i) {
		if (!rem.count(i)) { leaves.insert(i); }
	}

	vector<pii> edges;
	for (int i = 0; i < n + m - 2; ++i) {
		const int other = *leaves.begin();
		leaves.erase(leaves.begin());
		int cur;
		if (other > n) {
			assert(aptr < SZ(A));
			cur = A[aptr++];
		} else {
			assert(bptr < SZ(B));
			cur = B[bptr++];
		}
		edges.emplace_back(cur, other);
		if (--rem[cur] == 0) {
			leaves.insert(cur);
		}
	}
	assert(SZ(leaves) == 2);
	edges.emplace_back(*leaves.begin(), *leaves.rbegin());

	cout << "Yes\n";
	for (auto [a, b] : edges) {
		cout << a << " " << b << "\n";
	}
}