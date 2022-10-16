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

const int N = 1e3 + 5;

int n, m;

char s[N], t[N];

bool inline check() {
	for (int i = 1; i <= n; i++) {
		if (s[i] != t[1]) continue;
		int k = 0;
		for (int j = i; j <= n; j++) {
			if (s[j] == t[k + 1]) {
				++k;
				if (k == m) return 1;
				int la = m - k;
				if (j - la + 1 >= 1) {
					bool o = 1;
					for (int x = 1; x <= la; x++) {
						if (s[j - x] != t[k + x]) {
							o = 0;
						}
					}
					if (o) return 1;
				}
			} else break;
		}
	}
	return 0;
}

int main() {
	int T; read(T);
	while (T--) {
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		puts(check() ? "YES" : "NO");
	}
	return 0;
}