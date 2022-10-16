// Skyqwq
#include <bits/stdc++.h>

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

const int N = 2005;

typedef pair<int, int> PII;

int n, f[N];

char g[N][N];

PII e[N][N];

int main() {
	memset(f, -1, sizeof f);
	read(n);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	if (n & 1) {
		puts("NONE");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		e[i][i].fi = i <= n / 2 ? i : n - i + 1;
		if (i > 1) e[i][i - 1] = mp(1, i & 1);
	}
	int c = 1;
	for (int i = 1; i <= n; i++) {
		e[i][1] = mp(c, (c % 2 == 0));
		if (i % 2 == 0) ++c;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j + 1 < i; j++) {
			if (e[i - 1][j - 1].fi == e[i - 2][j].fi) {
				e[i][j] = e[i - 1][j + 1];
				e[i][j].se ^= 1;
			} else {
				e[i][j] = e[i - 1][j - 1];
				e[i][j].se ^= 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
    		e[j][i] = e[i][j];
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		if (g[i][j] != '.') {
    			int v = g[i][j] == 'S';
    			PII t = e[i][j];
    			if (f[t.fi] != -1 && f[t.fi] != (v ^ t.se)) {
    				puts("NONE");
					return 0;
    			}
    			f[t.fi] = v ^ t.se;
    		}	
    	}
    }
    for (int i = 1; i <= n / 2; i++) {
    	if (f[i] == -1) {
    		puts("MULTIPLE");
    		return 0;
		}
    }
    puts("UNIQUE");
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		PII t = e[i][j];
    		int v = f[t.fi] ^ t.se;
    		char c = v ? 'S' : 'G';
    		putchar(c);
    	}
    	puts("");
    }
	return 0;
}