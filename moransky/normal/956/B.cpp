// Skyqwq
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

const int N = 1e5 + 5;
const double eps = 1e-14;
int n, U, e[N], q[N];
long double w[N];

bool inline chk(long double x) {
	for (int i = 1; i < n; i++)
		w[i] = -x * e[i] + e[i + 1];
	int hh = 1, tt = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j + 1 < i) {
			while (hh <= tt && w[j] <= w[q[tt]]) tt--;
			q[++tt] = j;
			++j;
		}
		while (hh <= tt && e[i] - e[q[hh]] > U) hh++;
		if (hh <= tt) {
			if (e[i] * (1 - x) >= w[q[hh]]) return 1;
		}
	}
	return 0;
}

int main() {
	read(n), read(U);
	for (int i = 1; i <= n; i++) read(e[i]);
	double l = 0, r = 1;
	while (r - l > eps) {
		double mid = (l + r) / 2;
		if (chk(mid)) l = mid;
		else r = mid;
	}
	if (!chk(l)) puts("-1");
	else printf("%.11lf\n", l);
    return 0;
}