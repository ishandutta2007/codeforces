// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5;

int n, p[N], q[N], pos[N], ans;

struct Node{
	int suf, s;
} t[N << 2];

Node operator + (Node a, Node b) {
	return (Node) { max(b.suf, b.s + a.suf), a.s + b.s };
}

#define ls (p << 1)
#define rs (p << 1 | 1)

void chg(int p, int l, int r, int x, int y) {
	if (l == r) {
		t[p].s += y;
		t[p].suf = max(t[p].s, 0);
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) chg(ls, l, mid, x, y);
	else chg(rs, mid + 1, r, x, y);
	t[p] = t[ls] + t[rs];
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(p[i]), pos[p[i]] = i;
    for (int i = 1; i <= n; i++) read(q[i]);
    ans = n;
	chg(1, 1, n, pos[n], 1);
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans);
		if (i == n) break;
		chg(1, 1, n, q[i], -1);
		while (t[1].suf <= 0) {
			chg(1, 1, n, pos[--ans], 1);
		}
	}	
    return 0;
}