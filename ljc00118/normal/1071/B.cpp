#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
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

const int N = 2005;

vector < pair <int, int> > FF[N + N];
vector < pair <int, int> > :: iterator it;

int f[N][N];
char c[N][N];
bool vis[N][N];
int x[N], y[N];
int n, m, len, maxn = 0;

int main() {
	memset(f, 0x3f, sizeof(f));
	cin >> n >> m;
	f[0][1] = f[1][0] = 0;
	for(register int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= n; j++) {
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + (c[i][j] != 'a');
			FF[i + j].push_back(make_pair(i, j));
		}
	}
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= n; j++)
		if(f[i][j] <= m) {
			if(i + j > maxn) {
				maxn = i + j;
				len = 1;
				x[1] = i; y[1] = j;
			} else if(i + j == maxn) {
				len++;
				x[len] = i;
				y[len] = j;
			}
		}
	}
	for(register int i = 2; i <= maxn; i++) putchar('a');
	if(len == 0) {
		len = 1;
		x[1] = 1;
		y[1] = 1;
		putchar(c[1][1]);
		maxn = 2;
	}
	for(register int i = maxn + 1; i <= n + n; i++) {
		int minn = 'z';
		for(register int j = 1; j <= len; j++) {
			if(x[j] != n) if(c[x[j] + 1][y[j]] < minn) minn = c[x[j] + 1][y[j]];
			if(y[j] != n) if(c[x[j]][y[j] + 1] < minn) minn = c[x[j]][y[j] + 1];
		}
		putchar(minn);
		for(register int j = 1; j <= len; j++) {
			if(x[j] != n) if(c[x[j] + 1][y[j]] == minn) vis[x[j] + 1][y[j]] = 1;
			if(y[j] != n) if(c[x[j]][y[j] + 1] == minn) vis[x[j]][y[j] + 1] = 1;
		}
		len = 0;
		for(it = FF[i].begin(); it != FF[i].end(); it++) {
			if(vis[it -> first][it -> second]) {
				x[++len] = it -> first, y[len] = it -> second;
			}
		}
	}
	return 0;
}