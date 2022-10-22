#include <cstdio>
#include <vector>
using namespace std;

const int Maxm = 105;

int n, k;
vector <int> has[Maxm];
vector <int> res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		has[a].push_back(i);
	}
	for (int i = 0; i < Maxm; i++)
		for (int j = 0; j < has[i].size() && i <= k; j++) {
			res.push_back(has[i][j]);
			k -= i;
		}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}