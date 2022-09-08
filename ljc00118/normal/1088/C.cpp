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

const int N = 2005;

int a[N];
int n, sum;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(a[i]);
	print(n + 1, '\n');
	for(register int i = n; i >= 1; i--) {
		print(1, ' '); print(i, ' ');
		int now = (i - 1 - a[i] % n - sum % n + n * 233) % n;
		print(now, '\n'); sum += now;
	}
	print(2, ' '); print(n, ' '); print(n, ' ');
	return 0;
}