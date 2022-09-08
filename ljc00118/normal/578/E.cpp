#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

set <int> p[2];
set <int> :: iterator it, it2;
char c[N];
int res[N], ans[N];
int n, cnt, minn = N;

inline int getfir() {
	int ans = N;
	if (p[0].size()) ans = min(ans, *p[0].begin());
	if (p[1].size()) ans = min(ans, *p[1].begin());
	return ans;
}

void solve() {
	for (int i = 1; i <= n; i++) p[c[i] == 'R'].insert(i);
	int now = 0, cnt = 0, opt = (c[0] == 'R');
	for (int i = 1; i <= n; i++) {
		it = p[opt ^ 1].lower_bound(now);
		if (it == p[opt ^ 1].end()) {
			now = ans[i] = *p[opt ^ 1].begin();
			p[opt ^ 1].erase(p[opt ^ 1].begin());
			++cnt; opt ^= 1;
			continue;
		}
		int fir = getfir();
		if (*it == fir) {
			now = ans[i] = *it;
			p[opt ^ 1].erase(it);
			opt ^= 1;
			continue;
		}
		it2 = p[opt].lower_bound(*it);
		if (it2 == p[opt].end() && p[opt].size() && *p[opt].begin() != fir) {
			now = ans[i] = *p[opt ^ 1].begin();
			p[opt ^ 1].erase(p[opt ^ 1].begin());
			++cnt; opt ^= 1;
			continue;
		}
		now = ans[i] = *it;
		p[opt ^ 1].erase(it);
		opt ^= 1;
	}
	if (cnt < minn) {
		minn = cnt;
		for (int i = 1; i <= n; i++) res[i] = ans[i];
	}
}

int main() {
	scanf("%s", c + 1); n = strlen(c + 1);
	for (int i = 1; i <= n; i++) cnt += (c[i] == 'L');
	if (n % 2 == 0) {
		c[0] = 'L'; solve();
		c[0] = 'R'; solve();
	} else if (cnt == n / 2) {
		c[0] = 'L'; solve();
	} else {
		c[0] = 'R'; solve();
	}
	print(minn, '\n');
	for (int i = 1; i <= n; i++) print(res[i], i == n ? '\n' : ' ');
    return 0;
}