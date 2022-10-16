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

LL a[10];

string c = "codeforces";

int main() {
	LL k; cin >> k;
	for (int i = 0; i < 10; i++) a[i] = 1;
	while (1) {
		long double v = 1;
		for (int i = 0; i < 10; i++) {
			v *= a[i];
		}
		if (v >= k) {
			for (int i = 0; i < 10; i++) {
				while (a[i]--) cout << c[i];
			}
			puts("");
			return 0;
		}
		LL mn = 2e9, p;
		for (int i = 0; i < 10; i++) {
			if (a[i] < mn) mn = a[i], p = i;
		}
		a[p]++;
	}
    return 0;
}