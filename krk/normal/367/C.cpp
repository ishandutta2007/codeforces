#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxm = 100005;

int n, m;
int w[Maxm];
ll res;
int bst = 0;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int q; scanf("%d %d", &q, &w[i]);
	}
	sort(w, w + m);
	for (int i = 1; i <= m; i++) {
		ll edges = ll(i) * (i - 1) / 2;
		ll got = i % 2? 1 + edges: i / 2 + edges;
		if (got <= n) bst = i;
	}
	for (int i = 1; i <= bst; i++)
		res += w[m - i];
	printf("%I64d\n", res);
	return 0;
}