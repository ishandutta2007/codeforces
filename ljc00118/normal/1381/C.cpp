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

priority_queue <pii> Q;
stack <int> st[N];
int a[N], cnt[N], ans[N], seq[N];
int T, n, x, y, col, len;

int main() {
	read(T);
	while (T--) {
		read(n); read(x); read(y);
		while (!Q.empty()) Q.pop();
		for (int i = 1; i <= n + 1; i++) cnt[i] = ans[i] = 0;
		for (int i = 1; i <= n; i++) read(a[i]), ++cnt[a[i]], st[a[i]].push(i);
		for (int i = 1; i <= n + 1; i++) {
			Q.push(make_pair(cnt[i], i));
			if (!cnt[i]) col = i;
		}
		y -= x;
		for (int i = 1; i <= x; i++) {
			pii u = Q.top(); Q.pop();
			int pos = st[u.second].top();
			st[u.second].pop();
			ans[pos] = a[pos];
			Q.push(make_pair(u.first - 1, u.second));
		}
		len = 0;
		for (int i = 1; i <= n + 1; i++) while (!st[i].empty()) seq[++len] = st[i].top(), st[i].pop();
		int maxn = Q.top().first;
		if (y) {
			for (int i = 1; i <= len; i++) {
				int go = (i + maxn - 1) % len + 1;
				if (a[seq[i]] != a[seq[go]]) {
					ans[seq[i]] = a[seq[go]];
					--y;
					if (!y) break;
				}
			}
		}
		if (y) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for (int i = 1; i <= n; i++) {
			if (!ans[i]) ans[i] = col;
			print(ans[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}