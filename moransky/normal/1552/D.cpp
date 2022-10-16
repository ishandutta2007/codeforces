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

const int N = 10;

int n, a[N];

set<int> s;

bool inline chk() {
	for (int i = 0; i < n; i++) if (a[i] == 0) return 1;
	for (int i = 1; i < (1 << n); i++) {
		int c = 0;
		for (int j = 0; j < n; j++)
			if (i >> j & 1) c += a[j];
		if (s.count(c)) return 1;
		s.insert(c);
	}
	return 0;
}

int main() {
	int T; read(T);
	while (T--) {
		s.clear();
		read(n);
		for (int i = 0; i < n; i++) {
			read(a[i]);
			if (a[i] < 0) a[i] *= -1;
		}
		puts(chk() ? "YES" : "NO");
	}
	return 0;
}