// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

typedef pair<int, int> PII;
 
const int N = 1e5 + 5;

int n, f[N], t, len, p[N], a[N];

PII e[N];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
    f[find(x)] = find(y);
} 

char s[N];

vector<int> ans[4];

void inline ask() {
	if (!t) return;
	printf("Q %d ", t);
	for (int i = 1; i <= t; i++)
		printf("%d %d ", e[i].fi, e[i].se);
	fflush(stdout);
	scanf("%s", s + 1);
	for (int i = 1; i <= t; i++) {
		if (s[i] == '1') merge(e[i].fi, e[i].se);
	}
}

void inline clear() {
	len = t = 0;
	for (int i = 1; i <= 3; i++) ans[i].clear();
}

int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) f[i] = i;
		for (int i = 1; i + 1 <= n; i += 2) 
			e[++t] = mp(i, i + 1);
		ask();
		t = 0;
		for (int i = 2; i + 1 <= n; i += 2) 
			e[++t] = mp(i, i + 1);
		ask();
		for (int i = 1; i <= n; i++) {
			int j = i;
			while (j < n && find(j + 1) == find(i)) j++;
			p[++len] = i;
			i = j;
		}
		t = 0;
		for (int i = 1; i + 2 <= len; i += 4) {
			e[++t] = mp(p[i], p[i + 2]);
		}
		ask();
		t = 0;
		for (int i = 2; i + 2 <= len; i += 4) {
			e[++t] = mp(p[i], p[i + 2]);
		}
		ask();
		t = 0;
		for (int i = 3; i + 2 <= len; i += 4) {
			e[++t] = mp(p[i], p[i + 2]);
		}
		ask();
		t = 0;
		for (int i = 4; i + 2 <= len; i += 4) {
			e[++t] = mp(p[i], p[i + 2]);
		}
		ask();
		a[find(p[1])] = 1;
		a[find(p[2])] = 2;
		for (int i = 3; i <= len; i++) {
			if (find(p[i]) != find(p[i - 2])) {
				a[find(p[i])] = 6 - a[find(p[i - 1])] - a[find(p[i - 2])];
			}
		}
		for (int i = 1; i <= n; i++) {
			ans[a[find(i)]].pb(i);
		}
		printf("A ");
		for (int i = 1; i <= 3; i++)
			printf("%lu ", ans[i].size());
		puts("");
		for (int i = 1; i <= 3; i++) {
			for (int v: ans[i]) printf("%d ", v);
			puts("");
		}
		fflush(stdout);
		clear();
	}
	return 0;
}