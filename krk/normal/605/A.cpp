#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
int isin[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		isin[a[i]] = i;
	}
	for (int i = 1, j; i <= n; i = j) {
		int mx = isin[i];
		j = i + 1;
		while (j <= n && mx < isin[j]) {
			mx = isin[j]; j++;
		}
		res = max(res, j - i);
	}
	printf("%d\n", n - res);
	return 0;
}