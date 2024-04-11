// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2005, S = N << 1, P = 1e9 + 7;
 
int n, f[S][2], g[S][2], B = 2002;

char s[N], t[N];

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

void inline upd(char c, int o) {
	memcpy(g, f, sizeof g);
	memset(f, 0, sizeof f);
	for (int i = B - n; i <= B + n; i++) {
		if (!g[i][0]) continue;
		for (int j = 0; j < 2; j++) {
			if (c != '?' && c != (j + '0')) continue;
			int w = j * o;
			add(f[i + w][0], g[i][0]);
			add(f[i + w][1], g[i][1]);
		} 
	}
}

void inline gx() {
	for (int i = B - n; i <= B + n; i++) {
		if (!f[i][0]) continue;
		int w = abs(B - i);
		add(f[i][1], 1ll * w * f[i][0] % P);
	}
}

int main() {
	int T; read(T);
	while (T--) {
		read(n);
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		for (int i = 2; i <= n; i += 2) {
			if (s[i] == '0') s[i] = '1';
			else if (s[i] == '1') s[i] = '0';
			if (t[i] == '0') t[i] = '1';
			else if (t[i] == '1') t[i] = '0';
		}
		memset(f, 0, sizeof f);
		f[B][0] = 1;
		for (int i = 1; i <= n; i++) {
			upd(s[i], 1);
			upd(t[i], -1);
			gx();
		}
		printf("%d\n", f[B][1]);
	}
    return 0;
}