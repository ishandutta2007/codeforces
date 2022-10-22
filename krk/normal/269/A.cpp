#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
ii ka[Maxn];

int Power(int a, int p)
{
	int res = 1;
	for (int i = 0; i < p; i++) res *= a;
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &ka[i].first, &ka[i].second);
	sort(ka, ka + n);
	for (int i = 0; i + 1 < n; i++)
		if (ka[i + 1].first - ka[i].first >= 15) continue;
		else {
			int toone = Power(4, ka[i + 1].first - ka[i].first);
			int need = ka[i].second / toone + (ka[i].second % toone > 0);
			ka[i + 1].second = max(ka[i + 1].second, need);
		}
	int cantake = 4, cur = ka[n - 1].first + 1;
	while (ka[n - 1].second > cantake) { cur++; cantake *= 4; }
	printf("%d\n", cur);
	return 0;
}