// Skyqwq
#include <bits/stdc++.h>

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

const int N = 2e5 + 5;

int c[N], res;

set<int> s[N];
 
int main() {
	int n, m; read(n), read(m);
	for (int i = 1, u, v; i <= m; i++) {
		read(u), read(v);
		if (u > v) swap(u, v);
		s[u].insert(v);
	}
	for (int i = 1; i <= n; i++) {
		if (s[i].size()) c[i] = 1;
		res += c[i];
	}
	int q; read(q);
	while (q--) {
		int op; read(op);
		if (op == 1) {
			int x, y; read(x), read(y);
			if (x > y) swap(x, y);
			s[x].insert(y);
			if (!c[x]) c[x] = 1, res++;
		} else if (op == 2) {
			int x, y; read(x), read(y);
			if (x > y) swap(x, y);
			s[x].erase(y);
			if (!s[x].size()) c[x] = 0, res--;
		} else {
			printf("%d\n", n - res);
		}
	}
    return 0;
}