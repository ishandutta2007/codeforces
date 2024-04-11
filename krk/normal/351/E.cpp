#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 2005;
const int Maxm = 100005;

int n;
vector <int> ind[Maxm];
int BIT[Maxn];
vector <int> tmp;
int res;

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

int Get(int l, int r) { return Get(r) - Get(l - 1); }

int getMin(int v)
{
	tmp.resize(ind[v].size());
	for (int i = ind[v].size() - 1; i >= 0; i--)
		tmp[i] = (i == ind[v].size() - 1? 0: tmp[i + 1]) + Get(ind[v][i], n) - (ind[v].size() - i);
	int res = tmp[0];
	int sum = 0;
	for (int i = 0; i < ind[v].size(); i++) {
		sum += Get(1, ind[v][i] - 1) - i;
		res = min(res, (i + 1 < ind[v].size()? tmp[i + 1]: 0) + sum);
	}
	for (int i = 0; i < ind[v].size(); i++)
		Insert(ind[v][i], -1);
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		ind[abs(a)].push_back(i);
		Insert(i, 1);
	}
	for (int i = Maxm - 1; i >= 0; i--)
		if (!ind[i].empty()) res += getMin(i);
	printf("%d\n", res);
	return 0;
}