#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
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

	int n, l, k;
	cin >> n >> l >> k;
	--k;

	string info;
	cin >> info;
	sort(info.begin(), info.end());

	vector<string> ans(n, string(l, '.'));
	int ptr = 0;

	int top = 0;
	for (int loc = 0; loc < l; ++loc) {
		while (top < k && loc > 0 && ans[top][loc-1] != ans[k][loc-1]) {
			++top;
		}
		for (int i = top; i <= k; ++i) {
			ans[i][loc] = info[ptr++];
		}
	}
	

	for (auto &x : ans) {
		for (char &ch : x) {
			if (ch == '.') { ch = info[ptr++]; }
		}
		cout << x << "\n";
	}
}