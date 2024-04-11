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
const int INF = 1e9;

char s[N], t[N];

int n;
 
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		int c0 = 0, c1 = 0, d1 = 0, d0 = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] != t[i]) {
				if (s[i] == '0') c0++;
				else c1++;
			} else {
				if (s[i] == '0') d0++;
				else d1++;
			}
		}
		int ans = INF;
		if ((c0 + c1) % 2 == 0) {
			if (c0 == c1) chkMin(ans, c0 + c1);
		}
		if ((d0 + d1) % 2) {
			if (d1 == d0 + 1) chkMin(ans, d0 + d1);
		}
		if (ans == INF) ans = -1;
		printf("%d\n", ans);
	}
    return 0;
}