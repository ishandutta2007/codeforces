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

const int N = 2e5 + 5;

int s[N][30];
 
int main() {
	for (int i = 1; i <= 200000; i++) {
		for (int j = 0; j < 30; j++) {
			s[i][j] = s[i - 1][j] + 1;
			if (i >> j & 1) s[i][j]--;
		}
	}
	int T; read(T);
	while (T--) {
		int l, r; read(l), read(r);
		int ans = 2e9;
		for (int i = 0; i < 30; i++)
			chkMin(ans, (s[r][i] - s[l - 1][i]));
		printf("%d\n", ans);
	}
    return 0;
}