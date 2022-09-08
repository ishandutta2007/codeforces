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

const int N = 1e5 + 5;

char c[N], d[N];
int a[N];
int n, m, len;

int main() {
	read(n); read(m); scanf("%s", c + 1); memcpy(d, c, sizeof(d)); sort(d + 1, d + n + 1); len = unique(d + 1, d + n + 1) - d - 1; 
	if(m > n) { printf("%s", c + 1); for(register int i = 1; i <= m - n; i++) putchar(d[1]); putchar('\n'); }
	else {
		for(register int i = 1; i <= m; i++) a[i] = lower_bound(d + 1, d + len + 1, c[i]) - d;
		a[m]++; int now = m; while(a[now] == len + 1) a[now] = 1, a[--now]++; for(register int i = 1; i <= m; i++) putchar(d[a[i]]); putchar('\n'); 
	}
	return 0;
}

// Rotate Flower Round.