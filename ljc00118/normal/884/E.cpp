#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

const int N = 1 << 16 | 233;

int f[N], a[N];
char c[N];
int n, m, ans;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int merge(int x, int y) {
	int a = find(x), b = find(y);
	if(a != b) ans--, f[a] = b;
}

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n; i++) {
		scanf("%s", c + 1); int len = 0;
		for(register int j = 1; j <= m / 4; j++) {
			int num; if(c[j] >= '0' && c[j] <= '9') num = c[j] - '0';
			else num = c[j] - 'A' + 10;
			a[++len] = (num >> 3) & 1;
			a[++len] = (num >> 2) & 1;
			a[++len] = (num >> 1) & 1;
			a[++len] = num & 1; 
		}
		for(register int j = 1; j <= m; j++) {
			if(a[j]) ans++, f[j + m] = j + m;
			else f[j + m] = 0;
		}
		for(register int j = 1; j <= m; j++) {
			if(a[j]) {
				if(f[j]) merge(j, j + m);
				if(j > 1 && a[j - 1]) merge(j + m - 1, j + m);
			}
		}
		for(register int j = 1; j <= m; j++) {
			if(a[j]) f[j] = find(j + m) - m;
			else f[j] = 0;
		}
	}
	cout << ans << endl;
	return 0;
}