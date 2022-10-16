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

int n;

LL ans;

set<int> s;

int inline calc(int n) {
	s.clear(); int ans = 0;
	for (int a = 0; a <= n; a++) {
		for (int b = 0; a + b <= n; b++) {
			for (int c = 0; a + b + c <= n; c++) {
				int d = n - a - b - c;
				int v = a + b * 5 + c * 10 + d * 50;
				if (!s.count(v)) {
					s.insert(v);
					ans++;
				}
			}
		}
	}
	return ans;
}

int main() {
	LL A = calc(20);
	read(n);
	if (n <= 20) printf("%d\n", calc(n));
	else printf("%lld\n", A + (n - 20) * 49ll);
}