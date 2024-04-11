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

const int N = 45;

int n;

char s[N], g[N];

int main() {
	int T; read(T);
	while (T--) {
		read(n); scanf("%s", s + 1);
		for (int i = 1; i <= n; i++) g[i] = s[i];
		sort(g + 1, g + 1 + n);
		int c = 0;
		for (int i = 1; i <= n; i++)
			if (g[i] != s[i]) c++;
		printf("%d\n", c);
	}
	return 0;
}