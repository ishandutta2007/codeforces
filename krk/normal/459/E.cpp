#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 300005;

int n, m;
int best[Maxn];
vector <iii> E;
int tres[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &m); E.resize(m);
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &E[i].second.first, &E[i].second.second, &E[i].first);
	sort(E.begin(), E.end());
	for (int i = m - 1, j; i >= 0; i = j) {
		j = i;
		while (j >= 0 && E[i].first == E[j].first) {
			tres[j] = 1 + best[E[j].second.second];
			j--;
		}
		for (int l = j + 1; l <= i; l++)
			best[E[l].second.first] = max(best[E[l].second.first], tres[l]);
	}
	for (int i = 1; i <= n; i++)
		res = max(res, best[i]);
	printf("%d\n", res);
	return 0;
}