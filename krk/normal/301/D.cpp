#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 200005;

int n, m;
int p[Maxn];
vector <int> divs[Maxn];
int BIT[Maxn];
iii srted[Maxn];
vector <int> fil[Maxn];
int res[Maxn];

void Insert(int x, int val)
{
	for (int i = x; i < Maxn; i += i & -i)
		BIT[i] += val;
}

int Get(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		for (int j = p[i]; j < Maxn; j += p[i])
			divs[j].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &srted[i].first.first, &srted[i].first.second);
		srted[i].second = i;
	}
	sort(srted, srted + m);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < divs[p[i]].size(); j++) {
			int k = divs[p[i]][j];
			fil[min(i, k)].push_back(max(i, k));
			Insert(max(i, k), 1);
		}
	int lst = 1;
	for (int i = 0; i < m; i++) {
		while (lst < srted[i].first.first) {
			for (int j = 0; j < fil[lst].size(); j++)
				Insert(fil[lst][j], -1);
			lst++;
		}
		res[srted[i].second] = Get(srted[i].first.second);
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", res[i]);
	return 0;
}