#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 510;
struct Ope {
	int p, c;
};
vector <Ope> ans;
int n,a[maxn],st;
map <int, int> cnt;
queue <int> llen;
stack <int> rlen;

void rev_end(int L, int l, int r) {
	int len = r - l + 1;
	for (int i = r; i >= l; --i) ans.push_back({l - L + st + r - i, a[i]});
	rlen.push(2 * len);
	reverse(a + l, a + r + 1);
}

void solve(int L, int R) {
	if (L > R) return;
	if (a[L] != a[L + 1]) {
		for (int i = L + 1; i <= R; ++i)
			if (a[L] == a[i]) {
				rev_end(L, i, R), rev_end(L, L + 1, R);
				break;
			}
	}
	llen.push(2), st += 2;
	solve(L + 2, R);
}

void work() {
	cnt.clear();
	ans.clear();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), cnt[a[i]]++;
	for (pii p : cnt) if (p.second & 1) return printf("-1\n"), void();
	st = 0;
	solve(1, n);
	printf("%d\n", (int) ans.size());
	for (Ope t : ans) printf("%d %d\n", t.p, t.c);
	printf("%d\n", (int) llen.size() + (int) rlen.size());
	while (!llen.empty()) printf("%d ", llen.front()), llen.pop();
	while (!rlen.empty()) printf("%d ", rlen.top()), rlen.pop();
	printf("\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}