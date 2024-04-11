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

char Ask(int i, int j) {
	cout << "? " << i << " " << j << endl;
	char ans;
	cin >> ans;
	return ans;
}

void Test() {
	int n;
	cin >> n;

	const int M = 2 * n;

	vi chains[2];

	auto Add = [&](vi &where, int x) {
		for (int i = 0; i < SZ(where); ++i) {
			if (Ask(where[i], x) == '>') {
				where.insert(where.begin() + i, x);
				return;
			}
		}
		where.push_back(x);
	};
	
	for (int i = 1; i <= M; ++i) {
		int which = SZ(chains[0]) <= SZ(chains[1]) ? 0 : 1;
		Add(chains[which], i);
		if (SZ(chains[0]) + SZ(chains[1]) > n) {
			if (Ask(chains[0][0], chains[1][0]) == '<') {
				chains[0].erase(chains[0].begin());
			} else {
				chains[1].erase(chains[1].begin());
			}
		}
	}
	cout << "!" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) { Test(); }
}