#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int x[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i < n; i++) {
		int mn;
		if (i == 0) mn = x[1] - x[0];
		else if (i == n - 1) mn = x[n - 1] - x[n - 2];
		else mn = min(x[i] - x[i - 1], x[i + 1] - x[i]);
		int mx = max(x[n - 1] - x[i], x[i] - x[0]);
		printf("%d %d\n", mn, mx);
	}
	return 0;
}