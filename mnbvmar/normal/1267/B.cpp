#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define SZ(x) ((int)(x).size())
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

	string s;
	cin >> s;

	int n = SZ(s);

	vector<pair<char, int>> stk;
	char last = -1;
	int len = 0;
	for (char ch : s) {
		if (ch != last) {
			if (len) { stk.emplace_back(last, len); }
			last = ch;
			len = 1;
		} else {
			++len;
		}
	}
	stk.emplace_back(last, len);

	if (SZ(stk) % 2 == 0) {
		cout << "0\n";
		return 0;
	}
	const int S = SZ(stk);
	if (stk[S / 2].nd < 2) {
		cout << "0\n";
		return 0;
	}

	for (int i = 1; i <= S / 2; ++i) {
		const int L = S / 2 - i;
		const int R = S / 2 + i;
		if (stk[L].st != stk[R].st || stk[L].nd + stk[R].nd < 3) {
			cout << "0\n";
			return 0;
		}
	}

	cout << stk[S / 2].nd + 1 << "\n";
}