#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;

const int maxn = 1e5 + 10;
int n,m,p[maxn];
set <pii> s;

bool check() {
	for (int i = 1; i < n; ++i)
		if (s.find(make_pair(p[i], p[i + 1])) != s.end()) return 0;
	if (n == m && s.find(make_pair(p[n], p[1])) != s.end()) return 0;
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		s.insert(make_pair(x, y));
		s.insert(make_pair(y, x));
	}
	iota(p + 1, p + n + 1, 1);
	for (int T = 100; T--; ) {
		random_shuffle(p + 1, p + n + 1);
		if (!check()) continue;
		for (int i = 1; i < n && i <= m; ++i)
			printf("%d %d\n", p[i], p[i + 1]);
		if (n == m) printf("%d %d\n", p[n], p[1]);
		return 0;
	}
	printf("-1\n");
	return 0;
}