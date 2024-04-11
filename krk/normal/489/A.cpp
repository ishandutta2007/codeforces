#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 3005;

int n;
int a[Maxn];
ii res[Maxn];
int k;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		int mn = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[mn]) mn = j;
		if (mn != i) {
			res[k++] = ii(i, mn);
			swap(a[i], a[mn]);
		}
	}
	printf("%d\n", k);
	for (int i = 0; i < k; i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}