# include <cstdio>
# include <cstring>
using namespace std;

const int maxn = 1200;

int a[maxn], nxt[maxn], go[maxn];
int c[9], n;

short int f[maxn][256];

void upd(short int &x,const int &y) {
	if(y > x) x = y;
}

int calc(int k) {
	memset(f, -1, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 256; ++j) {
			if(f[i-1][j] == -1) continue;
			upd(f[i][j], f[i-1][j]);
			if(j >> (a[i] - 1) & 1) continue;
			upd(f[go[i]][j | 1<<(a[i] - 1)], f[i-1][j]);
			upd(f[nxt[go[i]]][j | 1<<(a[i] - 1)], f[i-1][j] + 1);
		}
	}
	return f[n][255];
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= 8; ++i) c[i] = n + 1;
	for(int i = n; i >= 1; --i) nxt[i] = c[a[i]], c[a[i]] = i;
	int ans = 0;
	for(int i = 1; i <= 8; ++i) if(c[i] != n + 1) ans += 1;
	for(int i = 1; i <= n; ++i) go[i] = i;
	go[n + 1] = nxt[n + 1] = n + 1;
	for(int k = 1; k * 8 <= n; ++k) {
		int val = calc(k);
		if(val != -1) ans = k * 8 + val;
		for(int i = 1; i <= n; ++i) go[i] = nxt[go[i]];
	}
	printf("%d\n", ans);
	return 0;
}