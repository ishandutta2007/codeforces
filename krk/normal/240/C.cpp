#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n;
vector <int> res[Maxn];
int len;

void Find(int l, int r, int lvl)
{
	if (l == r) return;
	len = max(len, lvl + 1);
	int m = (l + r - 1) / 2;
	for (int i = l; i <= m; i++) 
		res[lvl].push_back(i);
	Find(l, m, lvl + 1); Find(m + 1, r, lvl + 1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	Find(1, n, 0);
	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		printf("%d", res[i].size());
		for (int j = 0; j < res[i].size(); j++)
			printf(" %d", res[i][j]);
		printf("\n");
	}
	return 0;
}