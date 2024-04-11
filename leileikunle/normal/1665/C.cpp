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

const int N = 1e6 + 10, mod = 1e9 + 7, maxn = 10000010;;
int c[N];
void solve() {

	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) c[i] = 0;
	c[0]++;
	for (int i = 1, x; i < n; i++) cin >> x, c[x]++;

	sort(c, c + n + 1, greater<int>());

	auto check = [&](int x) -> bool{
		int cnt = 0;
		for (int i = 0; i <= n and c[i]; i++) {
			cnt++;
			cnt += (c[i] > x - i ? c[i] + i - x : 0);
		}
		return cnt <= x;
	};

	int l = 1, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;

}
signed main() {
	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
}