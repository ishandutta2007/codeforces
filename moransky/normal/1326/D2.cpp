// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return y > x ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
const int N = 2e6 + 5;

char s[N], g[N];

int n, t, p[N], f[N], nxt[N], len;

PII e[N];

void inline manacher() {
	int mid = 0, r = 0;
	for (int i = 1; i <= t; i++) {
		p[i] = i <= r ? min(r - i + 1, p[2 * mid - i]) : 1;
		while (g[i + p[i]] == g[i - p[i]]) ++p[i];
		if (i + p[i] - 1 > r) r = i + p[i] - 1, mid = i;
		e[++len] = mp((i + p[i] - 1) / 2 - (p[i] - 1) + 1, (i + p[i] - 1) / 2);
	}
}

bool st[N];

int main() {
	int T; read(T);
	while (T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		t = 0;
		g[0] = '#';
		for (int i = 1; i <= n; i++) {
			f[i] = 0;
			g[++t] = '?';
			g[++t] = s[i];
			st[i] = 0;
		}
		g[++t] = '?';
		g[++t] = '.';
		len = 0;
		manacher();
		int mx = 0;
		while (1 + mx < n - mx && s[1 + mx] == s[n - mx]) mx++; 
		int ans = 0;
		int A = 0, B = 0;
		for (int i = 1; i <= len; i++) {
			int l = e[i].fi, r = e[i].se;
			int o = n - r;
			if (o * 2 <= n && o <= mx && l > o) {
				if (chkMax(ans, r - l + 1 + 2 * o))
					A = o, B = l;
			}
			o = l - 1;
			if (o * 2 <= n && o <= mx && r < n - o + 1) {
				if (chkMax(ans, r - l + 1 + 2 * o))
					A = r, B = n - o + 1;
			}
		}
		for (int i = 1; i <= A; i++) putchar(s[i]);
		for (int i = B; i <= n; i++) putchar(s[i]);
		puts("");
	}
	return 0;
}