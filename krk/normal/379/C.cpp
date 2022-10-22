#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int n;
ii a[Maxn];
int res[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first); a[i].second = i;
	}
	sort(a, a + n);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur = max(cur + 1, a[i].first);
		res[a[i].second] = cur;
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}