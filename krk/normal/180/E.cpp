#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxm = 100005;

int n, m, k;
int lst[Maxm];
vector <int> acc[Maxm];
int res;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		int c; scanf("%d", &c);
		if (!lst[c]) acc[c].push_back(0);
		else acc[c].push_back(acc[c].back() + i - lst[c]);
		lst[c] = i + 1;
	}
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < acc[i].size(); j++) {
			int l = upper_bound(acc[i].begin(), acc[i].end(), acc[i][j] + k) - acc[i].begin();
			res = max(res, l - j);
		}
	printf("%d\n", res);
	return 0;
}