#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n, k;
ii a[Maxn];
vector <int> res[Maxn];
int cur = 1;

void Colour(int v, int hm)
{
	hm = min(hm, a[v].first); a[v].first -= hm;
	while (hm--) res[a[v].second].push_back(cur);
}

void colourAll(int from, int hm)
{
	for (int i = from; i < n; i++)
		Colour(i, hm);
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first); a[i].second = i;
	}
	sort(a, a + n);
	int dv = a[0].first / k;
	int hmb = a[0].first % k;
	int hma = k - hmb;
	for (int i = 1; i <= hma; i++) {
		cur = i;
		colourAll(0, dv);
	}
	for (int i = hma + 1; i <= hma + hmb; i++) {
		cur = i;
		colourAll(0, dv + 1);
	}
	for (int i = 0; i < n; i++)
		if (a[i].first > k) { printf("NO\n"); return 0; }
		else {
			cur = 1;
			while (a[i].first) { Colour(i, 1); cur++; }
		}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < res[i].size(); j++)
			printf("%d%c", res[i][j], j + 1 < res[i].size()? ' ': '\n');
	return 0;
}