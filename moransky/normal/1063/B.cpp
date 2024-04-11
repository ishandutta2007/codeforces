#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2e3 + 5;

typedef pair<int, int> PII;

int n, m, r, c, x, y, ans;

PII d[N][N];

int val(PII u) {
	if (u.se < c) return d[u.fi][u.se].se;
	return d[u.fi][u.se].fi;
}


struct E{
	int x, y, d;
	bool operator < (const E &b) const {
		return d > b.d;
	}
};

priority_queue<E> q;

char s[N][N];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool vis[N][N];

int main() {
	memset(d, 0x3f, sizeof d);
	read(n), read(m), read(r), read(c), read(x), read(y);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	q.push((E) { r, c, 0 } );
	d[r][c] = mp(0, 0);
	while (!q.empty()) {
		E u = q.top(); q.pop();
		if (vis[u.x][u.y]) continue;
		vis[u.x][u.y] = 1;
		PII w = d[u.x][u.y];
		if (w.fi <= x && w.se <= y) ans++;
		for (int i = 0; i < 4; i++) {
			int nx = u.x + dx[i], ny = u.y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] == '*') continue;
			PII t = w;
			if (dy[i] == -1) t.fi++;
			if (dy[i] == 1) t.se++;
			if (t.fi < d[nx][ny].fi && t.se < d[nx][ny].se) {
				d[nx][ny] = t;
				q.push((E) { nx, ny, val(mp(nx, ny )) });
			}
		}
	}
	print(ans);
}