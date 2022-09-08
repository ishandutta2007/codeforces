#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Forr(i, a, b) for(register int i = a; i >= b; i--)
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

const int P = 998244353, N = 1e5 + 5;

void add(int &a, int b) {
	a += b;
	if(a >= P) a -= P;
	if(a < 0) a += P;
}

int f[N][205][2], s[N][205][2];
int a[N], n, ans;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(a[i]);
	if(a[1] == -1) for(register int i = 1; i <= 200; i++) f[1][i][0] = 1;
	else f[1][a[1]][0] = 1;
	for(register int i = 1; i <= 200; i++) s[1][i][0] = s[1][i - 1][0] + f[1][i][0];
	for(register int i = 2; i <= n; i++) {
		if(a[i] == -1) {
			for(register int j = 1; j <= 200; j++) {
				add(f[i][j][0], s[i - 1][j - 1][1]);
				add(f[i][j][0], s[i - 1][j - 1][0]);
				add(f[i][j][1], s[i - 1][200][1] - s[i - 1][j - 1][1]);
				add(f[i][j][1], f[i - 1][j][0]);
			}
		} else {
			int j = a[i];
			add(f[i][j][0], s[i - 1][j - 1][1]);
			add(f[i][j][0], s[i - 1][j - 1][0]);
			add(f[i][j][1], s[i - 1][200][1] - s[i - 1][j - 1][1]);
			add(f[i][j][1], f[i - 1][j][0]);
		}
		for(register int j = 1; j <= 200; j++) s[i][j][0] = (s[i][j - 1][0] + f[i][j][0]) % P, s[i][j][1] = (s[i][j - 1][1] + f[i][j][1]) % P;
	}
	add(ans, s[n][200][1]); print(ans, '\n');
	return 0;
}