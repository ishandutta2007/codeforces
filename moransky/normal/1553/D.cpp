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

const int N = 1e5 + 5;

int n, m;

char s[N], t[N];

bool inline check() {
	if ((n % 2) != (m % 2)) return 0;
	int j = 1;
	for (int i = 1; i <= n; i ++) {
		if (s[i] == t[j]) {
			++j;
		} else {
			i++;
		}
	}
	return j > m;
}

int main() {
	int T; read(T);
	while (T--) {
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		if (m > n) puts("NO");
		else {
			bool o = check();
			if (n > m) {
				for (int i = 1; i < n; i++) s[i] = s[i + 1];
				s[n] = '0';
				--n;
			}
			o |= check();
			puts(o ? "YES" : "NO");
		}
	}
	return 0;
}