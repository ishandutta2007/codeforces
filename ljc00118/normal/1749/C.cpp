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

const int N = 2e5 + 5;

int a[N];
int T, n;

int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		sort(a + 1, a + n + 1);
		int l = 1, r = (n + 1) / 2, ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			int ok = 1;
			for (int j = mid; j <= mid * 2 - 1; j++) {
				if (a[j] > j - mid + 1) {
					ok = 0;
					break;
				}
			}
			if (ok) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		print(ans, '\n');
	}
	return 0;
}