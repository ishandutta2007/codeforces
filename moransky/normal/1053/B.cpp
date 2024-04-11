#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

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

const int N = 3e5 + 5;

int n, a[N], s[N], st[N], top;
int sum[N][2];

LL ans;

int inline ask(int l, int r, int x, int o) {
	if (s[l] > x) return 0;
	int p = upper_bound(s + l, s + 1 + r, x) - s - 1;
	return sum[p][o] - sum[l - 1][o];
}

int main() {
	read(n);
	sum[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		LL x; read(x);
		while (x) {
			a[i]++;
			x -= x & -x;
		}
		s[i] = s[i - 1] + a[i];
		for (int j = 0; j < 2; j++)
			sum[i][j] = sum[i - 1][j];
		sum[i][s[i] & 1]++;
	}
	for (int i = 1; i <= n; i++) {
		while (top && a[st[top]] <= a[i]) top--;
		st[++top] = i;
		for (int j = top; j; j--) {
			int L = st[j - 1] + 1, R = st[j];
			ans += ask(L - 1, R - 1, s[i] - a[R] * 2, s[i] & 1);
		}
	}
	print(ans);
}