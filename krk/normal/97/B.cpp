#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

vector <ii> pnts;
int n;
set <ii> S;

void Get(int l, int r)
{
	if (l > r) return;
	int m = l + r >> 1;
	for (int i = l; i <= r; i++) S.insert(ii(pnts[m].first, pnts[i].second));
	Get(l, m - 1); Get(m + 1, r);
}

int main()
{
	scanf("%d", &n);
	while (n--) {
		int x, y; scanf("%d %d", &x, &y);
		pnts.push_back(ii(x, y));
		S.insert(ii(x, y));
	}
	sort(pnts.begin(), pnts.end());
	Get(0, pnts.size() - 1);
	printf("%d\n", S.size());
	for (set <ii>::iterator it = S.begin(); it != S.end(); it++)
		printf("%d %d\n", it->first, it->second);
	return 0;
}