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

queue <int> q;
char a[N], b[N];
int dp[1 << 20], f[25], g[25], used[25];
int T, n, blocks, ans;

int main() {
	read(T);
	while (T--) {
		memset(dp, 0, sizeof(dp)); memset(f, 0, sizeof(f)); memset(g, 0, sizeof(g)); memset(used, 0, sizeof(used));
		read(n); scanf("%s%s", a + 1, b + 1);
		for (int i = 1; i <= n; i++) f[a[i] - 'a'] |= (1 << (b[i] - 'a')), g[a[i] - 'a'] |= (1 << (b[i] - 'a')), g[b[i] - 'a'] |= (1 << (a[i] - 'a'));
		blocks = 0;
		for (int u = 0; u <= 19; u++) {
			if (!used[u]) {
				used[u] = 1; q.push(u); ++blocks;
				while (!q.empty()) {
					int u = q.front(); q.pop();
					for (int i = 0; i <= 19; i++) {
						if (((g[u] >> i) & 1) && !used[i]) {
							used[i] = 1;
							q.push(i);
						}
					}
				}
			}
		}
		dp[0] = 1;
		for (int i = 0; i < (1 << 20) - 1; i++) {
			if (!dp[i]) continue;
			for (int j = 0; j < 20; j++) {
				if (!((i >> j) & 1) && !(f[j] & i)) {
					dp[i | (1 << j)] = 1;
				}
			}
		}
		ans = 0;
		for (int i = 0; i < (1 << 20); i++) if (dp[i]) ans = max(ans, __builtin_popcount(i));
		print(40 - blocks - ans, '\n');
	}
	return 0;
}