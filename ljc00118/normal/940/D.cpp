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

const int N = 1e5 + 5, INF = 1e9;

int a[N], b[N];
int n, minn = INF, maxn = -INF;

int main() {
	read(n); for(register int i = 1; i <= n; i++) read(a[i]);
	for(register int i = 1; i <= n; i++) {
		char c = getchar();
		while(c != '0' && c != '1') c = getchar();
		b[i] = c - '0';
	}
	for(register int i = 5; i <= n; i++) {
		if(b[i] == b[i - 1]) continue;
		if(b[i] == 0) rep(j, i - 4, i) minn = min(minn, a[j] - 1);
		if(b[i] == 1) rep(j, i - 4, i) maxn = max(maxn, a[j] + 1);
	}
	cout << maxn << " " << minn << endl; 
	return 0;
}

// Rotate Flower Round.