// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
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

const int N = 5e5 + 5;

int n, m, nxt[N], c[2];

char s[N], t[N], ans[N];

int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	for (int i = 1; i <= n; i++) c[s[i] - '0']++;
	for (int i = 2, j = 0; i <= m; i++) {
		while (j && t[j + 1] != t[i]) j = nxt[j];
		if (t[j + 1] == t[i]) ++j;
		nxt[i] = j;
	}
	int j = 0;
	for (int i = 1; i <= n; i++) {
		if (t[j + 1] == '1') {
			if (c[1]) c[1]--, ans[i] = '1', ++j;
			else {
				while (j && t[j + 1] != '0') j = nxt[j];
				if (t[j + 1] == '0') ++j;
				c[0]--, ans[i] = '0';
			}
		} else {
			if (c[0]) c[0]--, ans[i] = '0', ++j;
			else {
				while (j && t[j + 1] != '1') j = nxt[j];
				if (t[j + 1] == '1') ++j;
				c[1]--, ans[i] = '1';
			}
		}
		if (j == m) j = nxt[j];
	}
	for (int i = 1; i <= n; i++) printf("%c", ans[i]);
	return 0;
}