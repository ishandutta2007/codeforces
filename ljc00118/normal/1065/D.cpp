#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 123, INF = 0x7fffffff;
const int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
const int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
const int mx[8] = {1, 1, -1, -1, 1, -1, 0, 0};
const int my[8] = {1, -1, 1, -1, 0, 0, 1, -1};

struct ele {
	int u, x, y, zt;
	ele (int a = 0, int b = 0, int c = 0, int d = 0) { u = a; x = b; y = c; zt = d; }
};

queue <ele> q;
pair <int, int> f[N][12][12][4];
int a[N][N], n, x, y, ans1 = INF, ans2 = INF;

int main() {
	memset(f, 0x3f, sizeof(f)); read(n);
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= n; j++) {
			read(a[i][j]);
			if(a[i][j] == 1) x = i, y = j;
		}
	}
	f[1][x][y][0].first = f[1][x][y][0].second = f[1][x][y][1].first = f[1][x][y][1].second = f[1][x][y][2].first = f[1][x][y][2].second = 0;
	q.push(ele(1, x, y, 0)); q.push(ele(1, x, y, 1)); q.push(ele(1, x, y, 2));
	while(!q.empty()) {
		ele t = q.front(); q.pop();
		if(t.u == n * n) {
			if(f[t.u][t.x][t.y][t.zt].first < ans1) {
				ans1 = f[t.u][t.x][t.y][t.zt].first;
				ans2 = f[t.u][t.x][t.y][t.zt].second;
			} else if(f[t.u][t.x][t.y][t.zt].first == ans1) ans2 = min(ans2, f[t.u][t.x][t.y][t.zt].second);
			continue;
		}
		for(register int i = 0; i < 8; i++) {
			int x = t.x + dx[i], y = t.y + dy[i];
			if(x <= 0 || y <= 0 || x > n || y > n) continue;
			int to = (a[x][y] == t.u + 1) + t.u;
			if(f[to][x][y][0].first > f[t.u][t.x][t.y][t.zt].first + 1 + (t.zt != 0) || (f[to][x][y][0].first == f[t.u][t.x][t.y][t.zt].first + 1 + (t.zt != 0) && f[to][x][y][0].second > f[t.u][t.x][t.y][t.zt].second + (t.zt != 0))) {
				f[to][x][y][0].first = f[t.u][t.x][t.y][t.zt].first + 1 + (t.zt != 0); f[to][x][y][0].second = f[t.u][t.x][t.y][t.zt].second + (t.zt != 0);
				q.push(ele(to, x, y, 0));
			}
		}
		for(register int i = 0; i < 4; i++) {
			int x = t.x, y = t.y;
			while(x > 0 && y > 0 && x <= n && y <= n) {
				x += mx[i]; y += my[i];
				if(x <= 0 || y <= 0 || x > n || y > n) break;
				int to = (a[x][y] == t.u + 1) + t.u;
				if(f[to][x][y][1].first > f[t.u][t.x][t.y][t.zt].first + 1 + (t.zt != 1) || (f[to][x][y][1].first == f[t.u][t.x][t.y][t.zt].first + 1 + (t.zt != 1) && f[to][x][y][1].second > f[t.u][t.x][t.y][t.zt].second + (t.zt != 1))) {
					f[to][x][y][1].first = f[t.u][t.x][t.y][t.zt].first + 1 + (t.zt != 1); f[to][x][y][1].second = f[t.u][t.x][t.y][t.zt].second + (t.zt != 1);
					q.push(ele(to, x, y, 1));
				}
			}
		}
		for(register int i = 4; i < 8; i++) {
			int x = t.x, y = t.y;
			while(x > 0 && y > 0 && x <= n && y <= n) {
				x += mx[i]; y += my[i];
				if(x <= 0 || y <= 0 || x > n || y > n) break;
				int to = (a[x][y] == t.u + 1) + t.u;
				if(f[to][x][y][2].first > f[t.u][t.x][t.y][t.zt].first + 1 + (t.zt != 2) || (f[to][x][y][2].first == f[t.u][t.x][t.y][t.zt].first + 1 + (t.zt != 2) && f[to][x][y][2].second > f[t.u][t.x][t.y][t.zt].second + (t.zt != 2))) {
					f[to][x][y][2].first = f[t.u][t.x][t.y][t.zt].first + 1 + (t.zt != 2); f[to][x][y][2].second = f[t.u][t.x][t.y][t.zt].second + (t.zt != 2);
					q.push(ele(to, x, y, 2));
				}
			}
		}
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}