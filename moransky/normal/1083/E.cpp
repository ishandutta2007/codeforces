// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
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

const int N = 1e6 + 5;

int n, q[N];

LL f[N], ans;

struct Node{
	int x, y;
	LL a;
	bool operator < (Node b) const {
		return x < b.x;
	}
} e[N];

void inline upd(int i, int j) {
	chkMax(f[i], f[j] + 1ll * (e[i].x - e[j].x) * e[i].y - e[i].a);
}

double inline Y(int i) {
	return f[i];
}

double inline X(int i) {
	return e[i].x;
}

double inline K(int i, int j) {
	return (Y(i) - Y(j)) / (X(i) - X(j));
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(e[i].x), read(e[i].y), read(e[i].a);
	sort(e + 1, e + 1 + n);
	f[0] = 0;
	int hh = 0, tt = 0;
	for (int i = 1; i <= n; i++) {
		if (e[i].x == e[i + 1].x) continue;
		upd(i, q[tt]);
		if (hh < tt) {
			int l = hh, r = tt - 1;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (K(q[mid], q[mid + 1]) <= e[i].y) r = mid;
				else l = mid + 1;
			}
			upd(i, q[r]);
		}
		while (hh < tt && K(q[tt], q[tt - 1]) <= K(q[tt], i)) tt--;
		q[++tt] = i;
		chkMax(ans, f[i]);
	}
	print(ans);
	return 0;
}