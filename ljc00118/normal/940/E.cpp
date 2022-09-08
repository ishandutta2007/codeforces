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

ll f[N], s[N];
int st[N][20], lg[N];
int a[N], n, k;

int query(int l, int r) {
	int k = lg[r - l + 1];
	return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
	read(n); read(k);
	for(register int i = 1; i <= n; i++) read(a[i]), st[i][0] = a[i], s[i] = s[i - 1] + a[i];
	for(register int j = 1; j <= 18; j++) {
		for(register int i = 1; i <= n - (1 << j) + 1; i++) st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}
	lg[0] = -1; for(register int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
	for(register int i = 1; i <= n; i++) {
		f[i] = f[i - 1] + a[i];
		if(i >= k) f[i] = min(f[i], f[i - k] + s[i] - s[i - k] - query(i - k + 1, i)); 
	}
	cout << f[n] << endl;
	return 0;
}

// Rotate Flower Round.