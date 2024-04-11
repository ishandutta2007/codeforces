// Skyqwq
#include <bits/stdc++.h>

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

const int N = 1e5 + 5;

int n;

LL s, t;

map<LL, int> M;
 
int main() {
	read(n);
	t = (n - 1ll) * n / 2;
	while (n--) {
		int x; read(x);
		s += x;
		M[x]++;
	}
	int c = 0, p = 0;
	bool o = 1;
	for (auto g: M) {
		if (g.se > 2 || (g.se == 2 && g.fi == 0)) o = 0;
		else if (g.se == 2) c++, p = g.fi;
	}
	if (c > 1) o = 0;
	if (c) {
		if (M[p - 1]) o = 0;
	}
	if (!o) puts("cslnb");
	else {
		int f = (s - t) & 1;
		puts(f ? "sjfnb" : "cslnb");
	}
	return 0;
}