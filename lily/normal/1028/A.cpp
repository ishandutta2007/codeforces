#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)

int n, m;

int main() {
	read(n); read(m);
	int u, d, l, r;
	u = l = 999;
	d = r = 0;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 1; j <= m; j++) {
			if (s[j - 1] == 'B') {
				u = min(u, i);
				d = i;
				l = min(l, j);
				r = max(r, j);
			}
		}
	}
	printf("%d %d\n", (u + d) / 2, (l + r) / 2);


	return 0;
}