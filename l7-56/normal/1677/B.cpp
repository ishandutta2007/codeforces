#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e6 + 10;
int n, m;
char s[maxn];
char *a[maxn];
struct BIT {
	int c[maxn];
	void clr() { for (int i = 1; i <= m; ++i) c[i] = 0; }
	void add(int pos, int val) { for (; pos <= m; pos += pos & (-pos)) c[pos] += val; }
	void add(int l, int r, int val) {
		if (l > r) return;
		add(l, val), add(r + 1, -val);
	}
	int ask(int pos) {
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += c[pos];
		return res;
	}
} T;
bitset <maxn> f;
void work() {
	scanf("%d%d%s", &n, &m, s + 1);
	T.clr();
	for (int i = 1; i <= n; ++i) a[i] = s + (i - 1) * m;
	for (int j = 1; j <= m; ++j) f[j] = 0;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		int p1 = 0, p2 = 1;
		if (i == n) p2 = m + 1;
		else while (p2 <= m && a[i + 1][p2] == '0') ++p2;
		--p2;
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '1') {
				T.add(max(p1, 1), min(p2, j - 1), 1);
				if (p1 == 0) T.add(j, m, 1);
				p1 = j;
				if (!f[j]) f[j] = 1, ++cnt;
			}
			printf("%d ", T.ask(j) + cnt);
		}
	}
	printf("\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}