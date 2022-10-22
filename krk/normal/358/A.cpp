#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 1005;

int n;
int x[Maxn];
int a = -Inf, b, c = Inf;

bool Solve()
{
	for (int i = 0; i + 1 < n; i++)
		for (int j = i + 1; j + 1 < n; j++) {
			int a = min(x[i], x[i + 1]), b = max(x[i], x[i + 1]);
			int c = min(x[j], x[j + 1]), d = max(x[j], x[j + 1]);
			if (a < c && c < b && b < d || c < a && a < d && d < b)
				return false;
		}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	printf("%s\n", Solve()? "no": "yes");
	return 0;
}