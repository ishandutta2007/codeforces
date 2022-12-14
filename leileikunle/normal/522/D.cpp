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
const int N = 1e6 + 10, mod = 1e9 + 7, inf = 1e18;
struct Q {
	int l, r, id;
} q[N];
struct node {
	int l, r;
	int mi;
} tr[N * 4];
void pushup(int u) {
	tr[u].mi = min(tr[u << 1].mi, tr[u << 1 | 1].mi);
}
void build(int u, int l, int r) {

	tr[u] = {l, r};
	if (l == r) {
		tr[u].mi = inf;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void update(int u, int l, int r, int k) {
	if (tr[u].l >= l && tr[u].r <= r) {
		tr[u].mi = k;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid) update(u << 1, l, r, k);
	else update(u << 1 | 1, l, r, k);
	pushup(u);
}
int query(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].mi;
	int mid = tr[u].l + tr[u].r >> 1;
	int res = 1e18;
	if (l <= mid) res = min(res, query(u << 1, l, r));
	if (r > mid) res = min(res, query(u << 1 | 1, l, r));
	return res;
}
int n, m;
int a[N], pre[N], ans[N];
map<int, int> mp;
void solve() {

	cin >> n >> m;
	build(1, 1, n);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!mp[a[i]]) mp[a[i]] = i;
		else pre[i] = mp[a[i]], mp[a[i]] = i;
	}
	for (int i = 1; i <= m; i++) cin >> q[i].l >> q[i].r, q[i].id = i;
	sort(q + 1, q + m + 1, [](Q a, Q b) {
		return a.r < b.r;
	});

	int r = 1;
	for (int i = 1; i <= m; i++) {
		while (r <= q[i].r) {
			if (pre[r]) update(1, pre[r], pre[r], r - pre[r]);
			r++;
		}
		int res = query(1, q[i].l, r - 1);
		if (res == inf) res = -1;
		ans[q[i].id] = res;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << endl;
}

signed main() {
	int tt = 1;
	// cin>>tt;
	while (tt--) {
		solve();
	}
}