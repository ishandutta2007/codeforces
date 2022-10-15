#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
void read(int &a) {scanf("%d", &a);}
void read(LL &a) {scanf("%lld", &a);}

const int N = 1e5 + 5;

int n, m;
int a[N], b[N], c[N];
void work() {
	read(n);read(m);
	map <int, pair <int, int>> g;
 	for (int i = 1; i <= n * m; i++) {
		int x; read(x);
		a[i] = x;
		b[i] = x;
		c[i] = -1;
	}
	sort(b + 1, b + n * m + 1);
	b[n * m + 1] = -1;
	for (int i = 1; i <= n * m; i++) {
		int j = i;
		while (b[j] == b[i]) j++;
		g[b[i]] = {i, j - 1};
		i = j - 1;
	}
	int ans = 0;
	for (int i = 1; i <= n * m; i++) {
		auto & p = g[a[i]];
		int lo = p.first, hi = p.second;
		int row = (lo + m - 1) / m;
		for (int j = (row - 1) * m + 1 ; j < lo; j++) {
			if (c[j] != -1 && c[j] != a[i]) ans ++;
		}
		c[lo] = a[i];
		p.first ++;
	}
	printf("%d\n", ans);

}

int main() {
	int t;
	read(t);
	while (t--) work();
}