#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;

const int maxn = 5e4 + 10;
int n,a[maxn],lst[maxn * 2];
vi pw2;
vector <pii> ans;
void opt(int i, int j) {
	// printf("%d %d\n", i, j);
	int x = a[i], y = a[j];
	ans.push_back(make_pair(x, y));
	a[i] = abs(x - y), a[j] = x + y;
}

int id[maxn],tmp[maxn];
void solve(int l, int r) {
	if (r - l + 1 <= 2) return;
	int len = r - l + 1, p = (*--upper_bound(pw2.begin(), pw2.end(), len)), k = l;
	if (p == len) return solve(l, r - 1);
	// printf("[%d, %d] %d\n", l, r, p);
	// for (int i = l; i <= r; ++i) printf("%d%c", id[i], " \n"[i == r]);
	// for (int i = l; i <= r; ++i) printf("%d%c", a[id[i]], " \n"[i == r]);
	for (int i = 1; i <= len - p; ++i) {
		opt(id[l + p - 1 - i], id[l + p - 1 + i]);
		tmp[k++] = id[l + p - 1 - i];
	}
	// printf("->\n");
	// for (int i = l; i <= r; ++i) printf("%d%c", a[id[i]], " \n"[i == r]);
	int kk = k;
	for (int i = 1; i <= 2 * p - len - 1; ++i) tmp[kk++] = id[l + i - 1];
	for (int i = l; i < kk; ++i) id[i] = tmp[i];
	solve(l, k - 1), solve(k, kk - 1);
}
void work() {
	ans.clear();
	scanf("%d", &n);
	if (n == 2) return void(printf("-1\n"));
	for (int i = 1; i <= n; ++i) a[i] = id[i] = i;
	solve(1, n);
	// for (int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i == n]);
	int val = *lower_bound(pw2.begin(), pw2.end(), n), zero = 0;
	for (int i = 1; i <= n; ++i) lst[a[i]] = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == val) continue;
		if (lst[a[i]]) {
			int j = lst[a[i]];
			opt(j, i);
			zero = j;
			break;
		}
		lst[a[i]] = i;
	}
	// printf("%d %d\n", zero, val);
	// for (int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i == n]);
	for (int i = 1; i <= n; ++i)
		if (i != zero)
			while (a[i] != val) opt(zero, i), opt(zero, i);
	for (int i = 1; i <= n; ++i)
		if (i != zero) { opt(zero, i); break; }
	printf("%d\n", (int) ans.size());
	for (pii p : ans) printf("%d %d\n", p.first, p.second);
}

int main() {
	for (int i = 1; i <= 100000; i <<= 1) pw2.push_back(i);
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}