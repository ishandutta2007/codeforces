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

const int N = 105;

map <int, bool> pre;
int a[N];
int n, d, ans;

int calc(int x) {
	if(pre.count(x)) return d + 1;
	pre[x] = 1;
	int minn = 0x7fffffff;
	for(register int i = 1; i <= n; i++) minn = min(minn, abs(a[i] - x));
	return minn;
}

int main() {
	read(n); read(d);
	for(register int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + n + 1);
	for(register int i = 1; i <= n; i++) {
		if(calc(a[i] - d) == d) ans++;
		if(calc(a[i] + d) == d) ans++;
	}
	cout << ans << endl;
	return 0;
}