#include <cstdio>
#include <set>
using namespace std;

const int Maxn = 100005;

int n, m;
int col[Maxn];
bool is[Maxn];
set <int> Q[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &col[i]);
		is[col[i]] = true;
	}
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		if (col[a] != col[b]) { Q[col[a]].insert(col[b]); Q[col[b]].insert(col[a]); }
	}
	int i = 0;
	for (int j = 1; j < Maxn; j++)
		if (is[j] && (!i || Q[j].size() > Q[i].size()))
			i = j;
	printf("%d\n", i);
	return 0;
}