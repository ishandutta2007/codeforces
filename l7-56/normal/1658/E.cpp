#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2010;
int n,a[maxn][maxn],k,to[maxn * maxn];
struct node {
	int x, y, v;
};
vector <node> b;

int f[maxn * maxn];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]), b.push_back((node){i + j, i - j, a[i][j]});
	sort(b.begin(), b.end(), [] (node p, node q) { return p.v > q.v; });
	int mnx = n * 3, mxx = -n * 3, mny = n * 3, mxy = -n * 3;
	for (node p : b) {
		f[p.v] = (p.x - mnx > k) || (p.y - mny > k) || (mxx - p.x > k) || (mxy - p.y > k);
		if (!f[p.v]) mnx = min(mnx, p.x), mxx = max(mxx, p.x), mny = min(mny, p.y), mxy = max(mxy, p.y);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			putchar(f[a[i][j]] ? 'G' : 'M');
		putchar('\n');
	}
	return 0;
}