# include <iostream>
# include <cstdio>
# include <set>
using namespace std;

const int maxn = 520;

int a[maxn][maxn];
int c[maxn];
int n, m, q;
multiset<int> e;

int calc(int r) {
	int ret = 0, val = 0;
	for(int j = 1; j <= m; ++j) {
		if(a[r][j]) {
			val += 1;
			ret = max(ret, val);
		} else { 
			val = 0;
		}
	}
	ret = max(ret, val);
	return ret;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
		c[i] = calc(i);
		e.insert(c[i]);
	}

	while(q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		e.erase(e.find(c[x]));
		a[x][y] ^= 1;
		c[x] = calc(x);
		e.insert(c[x]);

		printf("%d\n", *e.rbegin());
	}
}