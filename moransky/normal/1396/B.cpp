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

int n;
 
int main() {
	int T; read(T);
	while (T--) {
		read(n); int s = 0, mx = 0;
		while (n--) {
			int x; read(x);
			s += x, chkMax(mx, x);
		}
		if (s & 1) puts("T");
		else {
			if (mx > s / 2) puts("T");
			else puts("HL");
		}
	}
	return 0;
}