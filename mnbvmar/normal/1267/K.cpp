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

ll binoms[60][60];

ll Binom(int n, int k) {
	if (n < 0 || k < 0 || k > n) { return 0; }
	return binoms[n][k];
}

ll SolveSeq(const vi &seq) {
	const int s = SZ(seq);
	debug(seq);

	ll ans = 1;

	int ptr = s - 1;
	for (int i = *max_element(ALL(seq)); i >= 0; --i) {
		int nptr = ptr;
		while (nptr >= 0 && seq[nptr] == i) { --nptr; }
		const int sz = ptr - nptr;
		int navail = s - (max(i, 1) - 1);
		navail -= (s-1-ptr);
		debug(i, navail, sz);

		ans *= Binom(navail, sz);

		ptr = nptr;
	}
	debug(ans);
	return ans;
}

void Test() {
	ll num;
	cin >> num;

	for (int row = 0; row < 60; ++row) {
		binoms[row][0] = 1;
		for (int col = 1; col <= row; ++col) {
			binoms[row][col] = binoms[row-1][col-1] + binoms[row-1][col];
		}
	}

	vi seq;
	for (int j = 2; num; ++j) {
		seq.push_back(num % j);
		num /= j;
	}

	sort(ALL(seq));
	ll ans = SolveSeq(seq);
	if (seq[0] == 0) {
		seq.erase(seq.begin());
		ans -= SolveSeq(seq);
	}
	cout << ans - 1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	//~ for (int i = 0; i < 500 * 1000; ++i) {
		//~ vi key;
		//~ int cpy = i;
		//~ for (int j = 2; cpy; ++j) {
			//~ key.push_back(cpy % j);
			//~ cpy /= j;
		//~ }

		//~ vi skey = key;
		//~ sort(ALL(skey));
		//~ if (skey == vi{0,0,0,0,2,3,3,4}) {
			//~ debug(i, key);
		//~ }
	//~ }

	int t;
	cin >> t;
	while (t--) { Test(); }
}