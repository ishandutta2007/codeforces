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

const int N = 1005;

double f[N][N];
bool vis[N][N];
int n, m;

double calc(int x, int y) {return y == 0 ? 0 : (double)x / (double)y;}

double dfs(int x, int y) {
	if(x == 0) return 0;
	if(y == 0) return 1;
	if(y < 0) return 0;
	if(vis[x][y]) return f[x][y]; vis[x][y] = 1;
	f[x][y] = calc(x, x + y) + calc(y, x + y) * calc(y - 1, x + y - 1) * calc(y - 2, x + y - 2) * dfs(x, y - 3) + calc(y, x + y) * calc(y - 1, x + y - 1) * calc(x, x + y - 2) * dfs(x - 1, y - 2);
	return f[x][y];
}

int main() {
	cin >> n >> m;
	printf("%.10lf\n", dfs(n, m));
	return 0;
}