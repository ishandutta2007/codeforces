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

const int N = 3e5 + 5, P = 998244353;

int n, m, k, l, nxt[N], pre[N], cnt[N], f[N];

bool ban[N];

void inline upd(int x, int y) {
	if (x == y) {
		ban[x] = 1;
		return;
	}
	if ((nxt[x] && nxt[x] != y) || (pre[y] && pre[y] != x)) {
		ban[x] = ban[y] = 1;
		return;
	} 
	nxt[x] = y, pre[y] = x;
}

bool vis[N];
 
int a[N], b[N], t;

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}


int main() {
	read(n), read(m), read(k);
	while (n--) {
		read(l);
		int u = 0;
		for (int i = 1, v; i <= l; i++) {
			read(v);
			if (i > 1) upd(u, v);
			u = v;
		}
	}
	for (int i = 1; i <= k; i++) {
		if (!pre[i] && !ban[i]) {
			int x = i;
			int c = 0;
			bool o = 1;
			while (1) {
				++c;
				if (ban[x]) { o = 0; break; }
				if (!nxt[x]) break;
				x = nxt[x];
			}
			if (o) {
				cnt[c]++;
			}
		}
	}
	for (int i = 1; i <= k; i++) {
		if (cnt[i]) {
			++t;
			a[t] = i, b[t] = cnt[i];
		}
	}
	f[0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= t; j++) {
			int x = a[j], y = b[j];
			if (i >= x) add(f[i], 1ll * f[i - x] * y % P);
		}
	}
	printf("%d\n", f[m]);
	return 0;
}