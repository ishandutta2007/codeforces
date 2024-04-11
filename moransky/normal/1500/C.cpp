// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
 
typedef long long LL;
 
char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)
 
void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}
 
void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}
 
const int N = 5005, P = 1e9 + 7;
 
int n, m, a[N][N], b[N][N], c[N], tot, len, v[N], v2[N], B = 131, w[N], now[N];
 
vector<int> g[N], s[N];
 
bool inline check(int c) {
	now[c] = 0;
	int o = 0;
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j + 1 < g[i].size(); j++) {
			o += a[g[i][j]][c] > a[g[i][j + 1]][c];
		}
		now[c] += a[g[i][0]][c] != a[g[i][g[i].size() - 1]][c];
	}
	return o;
}
bool inline check5(int c) {
	int o = 0;
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j + 1 < g[i].size(); j++) {
			o += a[g[i][j]][c] > a[g[i][j + 1]][c];
		}
	}
	return !o;
}
 
void inline upd(int i, int j) {
	for (int k = 1; k <= m; k++)
		w[k] -= a[i][k] > a[j][k];
}
 
void upd2(int t) {
	for (int k = 1; k <= m; k++)
		now[k] += a[s[t][0]][k] != a[s[t][s[t].size() - 1]][k];
}
 
void inline work(int c) {
	int t = 0;
	for (int i = 1; i <= len; i++) {
		int last = -1;
		int fl = 0; int bg = g[i][0], ed = g[i][g[i].size() - 1];
		for (int j = 0; j < g[i].size(); j++) {
			if (a[g[i][j]][c] == last) s[t].push_back(g[i][j]);
			else {
				if (j) {
					upd(g[i][j - 1], g[i][j]);
					fl = 1;
					upd2(t);
				}
				s[++t].push_back(g[i][j]);
			}
			last = a[g[i][j]][c];
		}
		if (fl) {
			for (int k = 1; k <= m; k++) {
				now[k] -= a[bg][k] != a[ed][k];
			}
			upd2(t);
		}
	}
	for (int i = 1; i <= t; i++) {
		g[i] = s[i];
		s[i].clear();
	}
	len = t;
}
 
bool vis[N];
 
bool inline check2() {
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			if (v[g[i][0]] != v[g[i][j]]) return false;
		}
	}
	return true;
}
 
bool inline check3(int c) {
	int o = 0;
	for (int i = 1; i <= len; i++) {
		if (a[g[i][0]][c] != a[g[i][g[i].size() - 1]][c]) o++;
	}
	return o;
}
 
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			v[i] = ((LL)v[i] * B + a[i][j]) % P;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &b[i][j]);
			v2[i] = ((LL)v2[i] * B + b[i][j]) % P;
		}
	len = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && v[j] == v2[i]) {
				g[1].push_back(j);
				vis[j] = 1;
				break;
			}
		}
	}
	if (g[1].size() != n) {
		puts("-1"); return 0;
	}
	for (int i = 1; i <= m; i++) w[i] = check(i);
	while (1) {
		if (check2()) break;
		bool ok = false;
		for (int i = 1; i <= m; i++) {
			if (now[i] && check5(i)) {
				ok = true;
				c[++tot] = i;
				work(i);
				//for (int j = 1; j <= m; j++) w[j] = check(j);
				break;
			}
		}
		if (!ok) {
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", tot);
	for (int i = tot; i; i--) printf("%d ", c[i]);
	return 0;
}