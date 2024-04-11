#include <bits/stdc++.h>
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

const int N = 4005;

bitset <N> dp;
int a[N];
int T, n, len;

int main() {
	read(T);
	while (T--) {
		read(n); len = 0;
		for (int i = 1; i <= n * 2; i++) read(a[i]);
		dp.reset(); dp[0] = 1;
		for (int l = 1, r; l <= n * 2; l = r + 1) {
			r = l;
			while (r < n * 2 && a[l] > a[r + 1]) ++r;
			dp |= (dp << (r - l + 1));
		}
		if (dp[n]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}