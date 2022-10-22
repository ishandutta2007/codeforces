#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, m;
ii C[Maxn];
int isin[Maxn];

int solveToLeft(int a, int len);

int solveToRight(int a, int len)
{
	int ind = lower_bound(C, C + n, ii(C[a].first + len + 1, 0)) - C - 1;
	if (a == ind) return C[a].second;
	int d = C[ind].first - C[a].first;
	int tims = len / d; len %= d;
	return tims % 2? solveToLeft(ind, len): solveToRight(a, len);
}

int solveToLeft(int a, int len)
{
	int ind = lower_bound(C, C + n, ii(C[a].first - len, 0)) - C;
	if (a == ind) return C[a].second;
	int d = C[a].first - C[ind].first;
	int tims = len / d; len %= d;
	return tims % 2? solveToRight(ind, len): solveToLeft(a, len);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &C[i].first); 
		C[i].second = i + 1;
	}
	sort(C, C + n);
	for (int i = 0; i < n; i++)
		isin[C[i].second] = i;
	while (m--) {
		int a, len; scanf("%d %d", &a, &len);
		a = isin[a];
		int rig = lower_bound(C, C + n, ii(C[a].first + len + 1, 0)) - C - 1;
		len -= C[rig].first - C[a].first;
		printf("%d\n", solveToLeft(rig, len));
	}
	return 0;
}