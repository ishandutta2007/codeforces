#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e6 + 5;

int n, L[N], R[N], v[N], w[N];

string op[N];

#define ls L[u]
#define rs R[u]

void dfs1(int u) {
	if (!u) return ;
	if (op[u] == "IN") return;
	dfs1(L[u]), dfs1(R[u]);
	if (op[u] == "AND") w[u] = w[ls] & w[rs];
	else if (op[u] == "OR") w[u] = w[ls] | w[rs];
	else if (op[u] == "XOR") w[u] = w[ls] ^ w[rs];
	else w[u] = !w[ls];
}

void dfs2(int u, int x) {
	if (!u) return ;
	if (op[u] == "IN") {
		v[u] = x;
		return; 
	}
	if (op[u] == "AND") {
		if (w[u] == 1) dfs2(ls, 0), dfs2(rs, 0);
		else {
			if (!w[ls] && !w[rs]) return;
			if (w[ls] == 0) dfs2(ls, 1);
			else if (w[rs] == 0) dfs2(rs, 1);
		}	
	} else if (op[u] == "OR") {
		if (w[u] == 0) dfs2(ls, 1), dfs2(rs, 1);
		else {
			if (w[ls] && w[rs]) return;
			if (w[ls] == 1) dfs2(ls, 0);
			else if (w[rs] == 1) dfs2(rs, 0);
		}	
	} else if (op[u] == "XOR") dfs2(ls, !w[ls]), dfs2(rs, !w[rs]);
	else dfs2(ls, !w[ls]);
}

int main() {
	memset(v, -1, sizeof v);
	read(n);
	for (int i = 1; i <= n; i++) {
		cin >> op[i];
		if (op[i] == "IN") {
			read(w[i]);
		} else if (op[i] == "NOT") {
			read(L[i]);
		} else {
			read(L[i]), read(R[i]);
		}
	}
	dfs1(1);
	dfs2(1, !w[1]);
	for (int i = 1; i <= n; i++) {
		if (op[i] == "IN") {
			printf("%d", (~v[i] && v[i] != w[i]) ^ w[1]);
		}
	}
}