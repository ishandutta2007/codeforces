#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Forr(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 3e5 + 5;

vector <int> G[N];
int f[N][26], vis[N][26];
char c[N];
int n, m, ans;

void dfs(int x, int y) {
	if(vis[x][y]) {
		printf("-1\n");
		exit(0);
	}
	if(~f[x][y]) return;
	vis[x][y] = 1; f[x][y] = 0;
	for(vector <int> :: iterator it = G[x].begin(); it != G[x].end(); it++) {
		dfs(*it, y);
		f[x][y] = max(f[x][y], f[*it][y]);
	}
	if(c[x] - 'a' == y) f[x][y]++;
	vis[x][y] = 0;
}

int main() {
	memset(f, -1, sizeof(f));
	read(n); read(m); scanf("%s", c + 1);
	while(m--) {
		int a, b; read(a); read(b);
		G[a].push_back(b);
	}
	For(i, 1, n) if(!vis[i][0]) For(j, 0, 25) dfs(i, j), ans = max(ans, f[i][j]);
	print(ans, '\n');
	return 0;
}