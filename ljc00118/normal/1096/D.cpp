#include <bits/stdc++.h>
#define int long long
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
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

const int N = 1e5 + 5;

int f[N][5], w[N];
char c[N];
int n;

int calc(char t) {
	if(t == 'h') return 1;
	if(t == 'a') return 2;
	if(t == 'r') return 3;
	if(t == 'd') return 4;
	return 0;
}

#undef int
int main() {
#define int long long
	memset(f, -1, sizeof(f));
	read(n); scanf("%s", c + 1);
	for(register int i = 1; i <= n; i++) read(w[i]);
	f[0][0] = 0;
	for(register int i = 0; i < n; i++) {
		int val = calc(c[i + 1]);
		for(register int j = 0; j <= 3; j++) {
			if(f[i][j] == -1) continue;
			if(val == j + 1) {
				if(f[i + 1][j + 1] == -1) f[i + 1][j + 1] = f[i][j];
				else f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j]);
				if(f[i + 1][j] == -1) f[i + 1][j] = f[i][j] + w[i + 1];
				else f[i + 1][j] = min(f[i + 1][j], f[i][j] + w[i + 1]);
			} else {
				if(f[i + 1][j] == -1) f[i + 1][j] = f[i][j];
				else f[i + 1][j] = min(f[i + 1][j], f[i][j]);
			}
		}
	}
	int ans = f[n][0];
	for(register int i = 0; i <= 3; i++) if(f[n][i] != -1) ans = min(ans, f[n][i]);
	cout << ans << endl;
	return 0;
}