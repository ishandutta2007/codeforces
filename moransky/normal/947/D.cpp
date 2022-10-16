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

const int N = 1e5 + 5;

char s[N], t[N];

int n, m, a[N], b[N], s1[N][2], s2[N][2], q, L1[N], L2[N];

bool inline chk(int A1, int B1, int A2, int B2) {
	if ((B1 & 1) != (B2 & 1)) return 0;
	if ((A1 % 3) != (A2 % 3) || (B2 && !B1)) A1--, B1 += 2;
	if (A1 < 0) return 0;
	while (A1 && (A1 % 3) != (A2 % 3)) {
		A1--;
	}
	if (B1 > B2) return 0;
	if ((A1 % 3) != (A2 % 3)) return 0;
	if (A1 < A2) return 0;
	return 1;
}

int main() {
	scanf("%s%s", s + 1, t + 1); read(q);
	n = strlen(s + 1), m = strlen(t + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = s[i] == 'A' ? 0 : 1;
		for (int j = 0; j < 2; j++)
			s1[i][j] = s1[i - 1][j];
		s1[i][a[i]]++;
		if (!a[i]) L1[i] = L1[i - 1] + 1;
	}
	for (int i = 1; i <= m; i++) {
		b[i] = t[i] == 'A' ? 0 : 1;
		for (int j = 0; j < 2; j++)
			s2[i][j] = s2[i - 1][j];
		s2[i][b[i]]++;
		if (!b[i]) L2[i] = L2[i - 1] + 1;
	}
	while (q--) {
		int l, r, x, y; read(l), read(r), read(x), read(y);
		int A1 = min(L1[r], r - l + 1), B1 = s1[r][1] - s1[l - 1][1];
		int A2 = min(L2[y], y - x + 1), B2 = s2[y][1] - s2[x - 1][1];
		putchar(chk(A1, B1, A2, B2) ? '1' : '0');
	}
    return 0;
}