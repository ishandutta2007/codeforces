// Skyqwq
#include <iostream>
#include <cstdio>
#include <set>
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
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2005;

int n, a[N], ans;
 
set<int> s;

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 0; i <= n; i++) {
		s.clear();
		bool o = 1;
		for (int j = 1; j <= i; j++) {
			if (s.count(a[j])) o = 0;
			s.insert(a[j]);
		}
		if (!o) continue;
		chkMax(ans, i);
		for (int j = n; j > i; j--) {
			if (s.count(a[j])) break;
			s.insert(a[j]);
			chkMax(ans, i + n - j + 1);
		}
	}
	printf("%d\n", n - ans);
	return 0;
}