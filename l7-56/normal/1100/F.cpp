#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 500010, B = 20;
int n,a[maxn],q;
vector <pii> t[maxn];
int r[B + 10], lst[B + 10];
void ins(int x, int p) {
	for (int bit = B; bit >= 0; --bit)
		if ((x >> bit) & 1) {
			if (!r[bit]) {
				r[bit] = x, lst[bit] = p;
				return;
			}
			if (lst[bit] < p) swap(r[bit], x), swap(lst[bit], p);
			x ^= r[bit];
		}
}

int ask(int p) {
	int res = 0;
	for (int bit = B; bit >= 0; --bit)
		if (r[bit] && lst[bit] >= p) res = max(res, res ^ r[bit]);
	return res;
}

int ans[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		t[r].push_back(make_pair(i, l));
	}
	for (int i = 1; i <= n; ++i) {
		ins(a[i], i);
		for (pii p : t[i])
			ans[p.first] = ask(p.second);
	}
	for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
	return 0;
}