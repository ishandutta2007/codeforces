// xtqqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5, L = 30;

int n, a[N], b[N], tr[N * L][2], w[N * L], idx;

void inline add(int x, int k) {
	int p = 0;
	for (int i = L - 1; ~i; i--) {
		int ch = x >> i & 1;
		if (!tr[p][ch]) tr[p][ch] = ++idx;
		p = tr[p][ch];
		w[p] += k;
	}
}

int inline query(int x) {
	int res = 0, p = 0;
	for (int i = L - 1; ~i; i--) {
		int ch = x >> i & 1;
		if (tr[p][ch] && w[tr[p][ch]]) p = tr[p][ch];
		else p = tr[p][!ch], res |= 1 << i;
		w[p]--;
	}
	return res;
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) read(b[i]), add(b[i], 1);
	for (int i = 1; i <= n; i++) printf("%d ", query(a[i]));
    return 0;
}