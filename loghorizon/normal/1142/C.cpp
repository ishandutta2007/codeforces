// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
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

typedef pair<LL, LL> Point;

Point operator - (Point x, Point y) {
	return mp(x.fi - y.fi, x.se - y.se);
}

LL inline cross(Point a, Point b) {
	return a.fi * b.se - a.se * b.fi;
}

bool inline isOn(Point a, Point b, Point c) {
	return cross(b - a, c - a) >= 0;
}

int n, s[N], top;

Point a[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i].fi), read(a[i].se), a[i].se -= a[i].fi * a[i].fi;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		while (top > 1 && isOn(a[s[top - 1]], a[s[top]], a[i])) top--;
		s[++top] = i;
	}
	int ans = 0;
	for (int i = 1; i < top; i++)
		if (a[s[i]].fi != a[s[i + 1]].fi) ans++;
	print(ans);
	return 0;
}