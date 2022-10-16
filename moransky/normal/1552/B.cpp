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

const int N = 50005;

int n, r[N][5];

bool inline cmp(int i, int j) {
	int c = 0;
	for (int k = 0; k < 5; k++)
		if (r[i][k] < r[j][k]) c++;
	return c >= 3;
}


int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 5; j++) read(r[i][j]);
		int a = 1;
		for (int i = 2; i <= n; i++) {
			if (cmp(i, a)) a = i;
		}
		bool o = 1;
		for (int i = 1; i <= n; i++) {
			if (i != a) if (cmp(i, a)) o = 0;
		}
		if (!o) puts("-1");
		else printf("%d\n", a);
	}
	return 0;
}