#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;

int n;
ii num[Maxn];
int res[Maxn];
int cur = 1;
int has[3];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &num[i].first); num[i].second = i;
	}
	sort(num, num + 2 * n);
	for (int i = 0; i < 2 * n; i++)
		if (i + 1 == 2 * n || num[i].first != num[i + 1].first) {
			res[num[i].second] = cur; has[cur]++; cur = 3 - cur;
		} else {
			res[num[i].second] = cur; res[num[i + 1].second] = 3 - cur;
			has[cur]++; has[3 - cur]++;
			int j = i + 2;
			while (j < 2 * n && num[i].first == num[j].first) j++;
			i = j - 1;
		}
	printf("%d\n", has[1] * has[2]);
	for (int i = 0; i < 2 * n; i++)
		if (!res[i]) res[i] = has[1]++ < n? 1: 2;
	for (int i = 0; i < 2 * n; i++)
		printf("%d%c", res[i], i + 1 < 2 * n? ' ': '\n');
	return 0;
}