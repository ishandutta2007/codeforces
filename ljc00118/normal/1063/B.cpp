#include <bits/stdc++.h>
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

const int N = 2005;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int val[4] = {0, 0, 1, 1};

struct ele {
	int x, y;
	ele () {}
	ele (int a, int b) {
		x = a, y = b;
	}
};

queue <ele> q;

int dis[N][N];
char c[N][N];
int n, m, x, y, _x, _y, ans = 0;

int main() {
	memset(dis, 0x3f, sizeof(dis));
	cin >> n >> m >> x >> y >> _x >> _y;
	for(register int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
	dis[x][y] = 0; q.push(ele(x, y));
	while(!q.empty()) {
		ele u = q.front(); q.pop();
		for(register int i = 0; i < 4; i++) {
			int _x = u.x + dx[i], _y = u.y + dy[i];
			if(_x <= 0 || _y <= 0 || _x > n || _y > m) continue;
			if(c[_x][_y] == '*' || dis[u.x][u.y] + val[i] >= dis[_x][_y]) continue;
			dis[_x][_y] = dis[u.x][u.y] + val[i]; q.push(ele(_x, _y));
		}
	}
	for(register int i = 1; i <= n; i++){
		for(register int j = 1; j <= m; j++) {
			if(dis[i][j] == dis[0][0]) continue;
			int a = _x, b = _y;
			if(j < y) a -= y - j;
			if(j > y) b -= j - y;
			int t = (dis[i][j] - abs(j - y)) >> 1;
			a -= t; b -= t;
			if(a >= 0 && b >= 0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}