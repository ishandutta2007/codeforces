#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
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

const int N = 1005;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct ele { int x, y; ele (int a = 0, int b = 0) : x(a), y(b) {} };

int dis[10][N][N];
bool used[N][N];
char c[N][N];
int a[10], ans[10];
int n, m, p, cur, qwq;

queue <ele> q, Q[2][10];
void bfs(int col) {
	memset(dis[col], -1, sizeof(dis[col]));
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= m; j++) {
			if(c[i][j] - '0' == col) {
				dis[col][i][j] = 0;
				q.push(ele(i, j));
			}
		}
	}
	while(!q.empty()) {
		int x = q.front().x, y = q.front().y; q.pop();
		for(register int i = 0; i < 4; i++) {
			int _x = x + dx[i], _y = y + dy[i];
			if(_x <= 0 || _y <= 0 || _x > n || _y > m) continue;
			if(c[_x][_y] == '#' || ~dis[col][_x][_y]) continue;
			dis[col][_x][_y] = dis[col][x][y] + 1; q.push(ele(_x, _y));
		}
	}
}

int main() {
	read(n); read(m); read(p);
	for(register int i = 1; i <= p; i++) read(a[i]);
	for(register int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
	for(register int i = 1; i <= p; i++) bfs(i);
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= m; j++) {
			int now = c[i][j] - '0';
			if(now >= 1 && now <= p) {
				++ans[now];
				used[i][j] = 1;
				Q[cur][now].push(ele(i, j));
			}
		}
	} 
	while(1) {
		bool chk = 1; ++qwq;
		for(register int col = 1; col <= p; col++) {
			while(!Q[cur][col].empty()) {
				int x = Q[cur][col].front().x;
				int y = Q[cur][col].front().y;
				Q[cur][col].pop();
				for(register int i = 0; i < 4; i++) {
					int _x = x + dx[i], _y = y + dy[i];
					if(_x <= 0 || _y <= 0 || _x > n || _y > m) continue;
					if(~dis[col][_x][_y] && (dis[col][_x][_y] - 1) / a[col] + 1 <= qwq && !used[_x][_y]) {
						used[_x][_y] = 1; ++ans[col]; chk = 0; 
						if(dis[col][_x][_y] / a[col] + 1 > qwq) Q[cur ^ 1][col].push(ele(_x, _y));
						else Q[cur][col].push(ele(_x, _y));
					}
				}
			}
		}
		cur ^= 1; if(chk) break;
	}
	for(register int i = 1; i <= p; i++) print(ans[i], ' ');
	return 0;
}