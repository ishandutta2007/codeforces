#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 200005;

int n;
vector <int> has[Maxn];
vector <int> res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		has[a].push_back(i);
	}
	int cur = 0;
	while (cur >= 0)
		if (!has[cur].empty()) { res.push_back(has[cur].back()); has[cur].pop_back(); cur++; }
		else cur -= 3;
	if (res.size() == n) {
		printf("Possible\n");
		for (int i = 0; i < res.size(); i++)
			printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	} else printf("Impossible\n");
	return 0;
}