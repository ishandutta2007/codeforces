#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
#define fir first
#define sec second
typedef vector <int> vi;
typedef vector <ll> vl;

const int maxn = 1e5 + 10;
int n, m, q, prs[maxn], prt[maxn], sbs[maxn], sbt[maxn];
char s[maxn], t[maxn], ans[maxn];

int check(int a, int b, int c, int d) {
	int ss = sbs[b] - sbs[a - 1], st = sbt[d] - sbt[c - 1];
	if (ss > st || (ss ^ st) & 1) return 0;
	int ls, lt;
	if (prs[b] >= a) ls = b - prs[b];
	else ls = b - a + 1;
	if (prt[d] >= c) lt = d - prt[d];
	else lt = d - c + 1;
	if (ls < lt) return 0;
	if (ls == lt && ss < st && ss == 0) return 0;
	if (ls > lt && ss == st && ls % 3 != lt % 3) return 0;
	return 1;
}

int main() {
	// freopen("always.in", "r", stdin), freopen("always.out", "w", stdout);
	scanf("%s%s%d", s + 1, t + 1, &q), n = strlen(s + 1), m = strlen(t + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'C') s[i] = 'B';
		prs[i] = s[i] == 'B' ? i : prs[i - 1];
		sbs[i] = sbs[i - 1] + (s[i] == 'B');
	}
	for (int i = 1; i <= m; ++i) {
		if (t[i] == 'C') t[i] = 'B';
		prt[i] = t[i] == 'B' ? i : prt[i - 1];
		sbt[i] = sbt[i - 1] + (t[i] == 'B');
	}
	for (int i = 1; i <= q; ++i) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		ans[i] = check(a, b, c, d) + '0';
	}
	printf("%s\n", ans + 1);
	return 0;
}