#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1005, INF = 0x7f7f7f7f;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct ele {
	int x, y;
	ele (int a = 0, int b = 0) : x(a), y(b) {}
};

queue <ele> Q;
char c[N][N];
int dis[N][N];
int n, m, q;

int main() {
	memset(dis, 0x7f, sizeof(dis));
	read(n); read(m); read(q);
	for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bool ok = 0;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (x <= 0 || y <= 0 || x > n || y > m) continue;
				if (c[i][j] == c[x][y]) {
					ok = 1;
					break;
				}
			}
			if (ok) {
				dis[i][j] = 0;
				Q.push(ele(i, j));
			}
		}
	}
	while (!Q.empty()) {
		ele u = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int x = u.x + dx[i], y = u.y + dy[i];
			if (x <= 0 || y <= 0 || x > n || y > m) continue;
			if (dis[x][y] > dis[u.x][u.y] + 1) {
				dis[x][y] = dis[u.x][u.y] + 1;
				Q.push(ele(x, y));
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y; ll t;
		read(x); read(y); read(t);
		if (dis[x][y] == INF) putchar(c[x][y]);
		else {
			if (t <= dis[x][y]) putchar(c[x][y]);
			else putchar(c[x][y] ^ ((t - dis[x][y]) & 1));
		}
		putchar('\n');
	}
    return 0;
}