#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, k;
int a[Maxn];
int tot;
vector <int> neg;
int lft;

int Get(int has)
{
	int pnt = 0;
	while (pnt < neg.size() && neg[pnt] <= has) { has -= neg[pnt]; pnt++; }
	return pnt;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int pnt = 0;
	while (pnt < n && a[pnt] >= 0) pnt++;
	if (pnt == n) { printf("0\n"); return 0; }
	int cnt = 0;
	for (int i = pnt, j; i < n; i = j) {
		j = i;
		while (j < n && a[j] < 0) j++;
		tot += j - i;
		i = j;
		while (j < n && a[j] >= 0) j++;
		if (j == n) lft = j - i;
		else neg.push_back(j - i);
		cnt++;
	}
	sort(neg.begin(), neg.end());
	int res = Maxn;
	if (tot <= k) res = min(res, 2 * cnt - 2 * Get(k - tot));
	if (tot + lft <= k) res = min(res, 2 * cnt - 1 - 2 * Get(k - tot - lft));
	printf("%d\n", res >= Maxn? -1: res);
	return 0;
}