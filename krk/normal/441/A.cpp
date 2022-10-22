#include <cstdio>
#include <vector>
using namespace std;

int n, v;
vector <int> res;

int main()
{
	scanf("%d %d", &n, &v);
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		bool deal = false;
		while (k--) {
			int p; scanf("%d", &p);
			deal |= v > p;
		}
		if (deal) res.push_back(i);
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}