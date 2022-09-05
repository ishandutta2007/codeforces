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
 
const int N = 1e5 + 5;

inline void addmin(int &x, int y) { x = min(x, y); }

ll a[N];
int dp[2][N], id[N], newid[N], s[N];
int n;

int main() {
	memset(dp, 0x7f, sizeof(dp));
	read(n);
	ll maxn = 0;
	for (int i = 1; i <= n; i++) read(a[i]), maxn = max(maxn, a[i]);
	for (int i = 1; i <= n; i++) a[i] = maxn - a[i], id[i] = i;
	dp[0][0] = 0;
	for (int bit = 0; bit <= 60; bit++) {
		memset(dp[(bit & 1) ^ 1], 0x7f, sizeof(dp[0]));
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + ((a[id[i]] >> bit) & 1);
		for (int i = 0; i <= n; i++) {
			// 0
			int go = s[i], cost = i - s[i] + s[n] - s[i];
			addmin(dp[(bit & 1) ^ 1][go], dp[bit & 1][i] + cost);
			// 1
			go = i + s[n] - s[i]; cost = n - cost;
			addmin(dp[(bit & 1) ^ 1][go], dp[bit & 1][i] + cost);
		}
		int tot = 0;
		for (int i = 1; i <= n; i++) if ((a[id[i]] >> bit) & 1) newid[++tot] = id[i];
		for (int i = 1; i <= n; i++) if (!((a[id[i]] >> bit) & 1)) newid[++tot] = id[i];
		for (int i = 1; i <= n; i++) id[i] = newid[i];
	}
	print(dp[0][0], '\n');
    return 0;
}