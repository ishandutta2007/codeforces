#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }
template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }

template <typename T> void inline read(T &x) {
	x = 0; int f = 1; char s = getchar();
	while (s > '9' || s < '0') { if (s == '-') f = -1; s = getchar(); }
	while (s <= '9' && s >= '0') x = x * 10 + s - '0', s = getchar();
	x *= f;
}

const int N = 1e5 + 5;

typedef pair<int, int> PII;

PII operator + (PII a, PII b) {
	return mp(a.fi + b.fi, a.se + b.se);
}

PII operator - (PII a, PII b) {
	return mp(a.fi - b.fi, a.se - b.se);
}

double calc(PII a) {
	return sqrt((double)a.fi * a.fi + (double)a.se * a.se);
}

int n;

PII a[N];

int p[N], ans[N];

void inline work() {
	for (int i = 1; i <= n; i++) p[i] = i;
	random_shuffle(p + 1, p + 1 + n);
	PII now = mp(0, 0);
	for (int j = 1; j <= n; j++) {
		int i = p[j];
		double v1 = calc(now + a[i]), v2 = calc(now - a[i]);
		if (v1 < v2) {
			now = now + a[i];
			ans[i] = 1;
		} else {
			now = now - a[i];
			ans[i] = -1;
		}
	}
	if (calc(now) <= 1.5e6) {
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]); 
		exit(0);
	}
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i].fi), read(a[i].se);
	for (int w = 1; w <= 200; w++) {
		work();
	}
	return 0;
}