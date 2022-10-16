// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

int inline get(int w) {
	printf("? %d\n", w);
	fflush(stdout);
	int x; read(x);
	return x;
}

int n;

int main() {
	read(n);
	int l = 1, r = n * 2000;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (get(mid) == 1) r = mid;
		else l = mid + 1;
	}	
	int ans = r;
	for (int i = 2; i <= n; i++) {
		// can in >= r - (i - 1)
		int o = 0;
		for (int j = r - (i - 1); j <= r; j++)
			if (j % i == 0) {
				o = j;
			}
		assert(o);
		int t = get(o / i);
		if (t) chkMin(ans, t * (o / i));
	}
	printf("! %d\n", ans);
	fflush(stdout);
    return 0;
}