#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
int has[Maxn];
vector <int> best;
int a, b;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int siz; scanf("%d", &siz);
		for (int i = 0; i < siz; i++)
			scanf("%d", &has[i]);
		int m = siz / 2;
		for (int i = 0; i < m; i++) {
			a += has[i]; b += has[siz - 1 - i];
		}
		if (siz % 2) best.push_back(has[m]);
	}
	sort(best.begin(), best.end());
	for (int i = 0; i < best.size(); i++)
		if (i % 2 == 0) a += best[best.size() - 1 - i];
		else b += best[best.size() - 1 - i];
	printf("%d %d\n", a, b);
	return 0;
}