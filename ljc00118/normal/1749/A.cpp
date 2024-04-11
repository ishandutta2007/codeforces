#include <bits/stdc++.h>
#include <Windows.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
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

const int N = 10;

int cx[N], cy[N];
int T, n, m;

int main() {
	read(T);
	while (T--) {
		memset(cx, 0, sizeof(cx));
		memset(cy, 0, sizeof(cy));
		read(n); read(m);
		for (int i = 1; i <= m; i++) {
			int x, y;
			read(x); read(y);
			++cx[x]; ++cy[y];
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) sum += max(0, cx[i] - 1), sum += max(0, cy[i] - 1);
		int ans = 1;
		if (sum == 0 && n == m) ans = 0;
		if (m > n) ans = 0;
		if (sum > 1) ans = 0;
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}