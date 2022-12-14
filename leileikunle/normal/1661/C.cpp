#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using pii = pair<int, int>;
#define all(a) begin(a), end(a)
#define lb(a, x) distance(begin(a), lower_bound(all(a), (x)))
#define ub(a, x) distance(begin(a), upper_bound(all(a), (x)))
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

const int N = 1e6 + 10, mod = 1e9 + 7;


int a[N];

void solve() {

	int n, mx(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]);

	auto calc = [&](int tar) -> int {

		int sum = 0, cnt(0);
		for (int i = 1; i <= n; i++) {
			int d = tar - a[i];
			sum += d;
			if (d & 1) cnt++;
		}
		return max(2 * cnt - 1, sum / 3 * 2 + sum % 3);
	};

	cout << min(calc(mx), calc(mx + 1)) << endl;
}
signed main() {
	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}



}
/*
6
1 5 3 9 6 2
*/