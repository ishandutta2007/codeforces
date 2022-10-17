// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5;

int n, fa[N], s[N];

vector<int> g[N];
 
int main() {
	read(n);
	for (int i = 2; i <= n; i++)
		read(fa[i]), g[fa[i]].pb(i);	
	for (int i = 1; i <= n; i++) read(s[i]);
	for (int i = 2; i <= n; i++) {
		if (s[i] == -1) {
			s[i] = 2e9;
			if (!g[i].size()) s[i] = s[fa[i]];
			for (int j = 0; j < g[i].size(); j++) {
				chkMin(s[i], s[g[i][j]]);
			}	
		}
	}
	bool o = 1;
	for (int i = 2; i <= n; i++)
		if (s[i] < s[fa[i]]) o = 0;
	if (!o) puts("-1");
	else {
		LL ans = 0;
		for (int i = 1; i <= n; i++)
			ans += s[i] - s[fa[i]];
		print(ans);
	}
	return 0;
}