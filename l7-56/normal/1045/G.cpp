#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename __Tp> void read(__Tp &x) {
	x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar());
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
}

const int maxn = 1e6 + 10;
int n,d,K;
struct node {
	int x,r,q,L,R;
}a[maxn],t[maxn];
vector <int> X;

ll ans;
struct BIT {
	int c[maxn];
	void add(int pos, int val) { for (; pos <= d; pos += pos & (-pos)) c[pos] += val; }
	int ask(int pos) {
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += c[pos];
		return res;
	}
	int ask(int l, int r) { return ask(r) - ask(l - 1); }
}c;
void solve(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	solve(l, mid), solve(mid + 1, r);
	int li = l, ri = l;
	for (int j = mid + 1; j <= r; ++j) {
		while (ri <= mid && a[ri].q <= a[j].q + K) c.add(a[ri].x, 1), ++ri;
		while (li < ri && a[li].q < a[j].q - K) c.add(a[li].x, -1), ++li;
		ans += c.ask(a[j].L, a[j].R);
	}
	while (li < ri) c.add(a[li].x, -1), ++li;

	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r)
		if (a[i].q <= a[j].q) t[k++] = a[i++];
		else t[k++] = a[j++];
	while (i <= mid) t[k++] = a[i++];
	while (j <= r) t[k++] = a[j++];
	for (i = l; i <= r; ++i) a[i] = t[i];
}

int main() {
	X.push_back(-1);
	read(n), read(K);
	for (int i = 1; i <= n; ++i) read(a[i].x), read(a[i].r), read(a[i].q), X.push_back(a[i].x);
	sort(a + 1, a + n + 1, [](node a, node b) { return a.r > b.r; });
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	d = X.size() - 1;
	for (int i = 1; i <= n; ++i)
		a[i].x = lower_bound(X.begin(), X.end(), a[i].x) - X.begin(),
		a[i].L = lower_bound(X.begin(), X.end(), X[a[i].x] - a[i].r) - X.begin(),
		a[i].R = upper_bound(X.begin(), X.end(), X[a[i].x] + a[i].r) - X.begin() - 1;
	// for (ll i = 1; i <= n; ++i) printf("%lld %lld %lld\n", a[i].x, a[i].r, a[i].q);
	solve(1, n);
	printf("%lld\n", ans);
	return 0;
}