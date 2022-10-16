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

const int N = 1e5 + 5;

int n, k, d[N], t;

char s[N];

int main() {
	int T; read(T);
	while (T--) {
		read(n), read(k);
		scanf("%s", s + 1);
		bool o = 1;
		for (int i = 1; i <= n; i++) if (s[i] == 'W') o = 0;
		if (o) {
			printf("%d\n", k == 0 ? 0 : 2 * min(n, k) - 1);
			continue;
		}
		t = 0;
		int la = 0;
		int sm = 0, ds = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'W') {
				if (la && la != i - 1) {
					d[++t] = i - la - 1;
				}
				if (!la || la != i - 1) ds++;
				la = i;
				sm++;
			}
		}
		int ans = min(n, sm + k) * 2;
		sort(d + 1, d + 1 + t);
		for (int i = 1; i <= t; i++) {
			if (k >= d[i]) {
				k -= d[i], ds--;
			}
		}
		ans -= ds;
		printf("%d\n", ans);
	}
    return 0;
}