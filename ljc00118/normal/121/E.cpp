#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Forr(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

char c[10];
int f[N], a[N], isGoodNum[N];
int n, m;

inline int lowbit(int x) { return x & -x; }
inline void add(int x, int y) { for(register int i = x; i <= n; i += lowbit(i)) f[i] += y; }
inline int qry(int x) { int ans = 0; for(register int i = x; i; i -= lowbit(i)) ans += f[i]; return ans; }

void dfs(int dep, int now) {
	if(dep == 0) return;
	isGoodNum[now] = 1;
	dfs(dep - 1, now * 10 + 4);
	dfs(dep - 1, now * 10 + 7);
}

int main() {
	read(n); read(m); dfs(5, 0);
	for(register int i = 1; i <= n; i++) read(a[i]);
	for(register int i = 1; i <= n; i++) if(isGoodNum[a[i]]) add(i, 1);
	while(m--) {
		scanf("%s", c + 1); int opt = c[1] == 'c';
		if(opt == 0) {
			int l, r, x; read(l); read(r); read(x);
			if(!x) continue;
			for(register int i = l; i <= r; i++) {
				int cnt = 0;
				if(isGoodNum[a[i]]) cnt--; a[i] += x;
				if(isGoodNum[a[i]]) cnt++;
				if(cnt != 0) add(i, cnt);
			}
		} else {
			int l, r; read(l); read(r);
			print(qry(r) - qry(l - 1), '\n');
		}
	}
	return 0;
}