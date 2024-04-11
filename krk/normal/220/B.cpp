#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 100005;

int n, m;
int a[Maxn];
map <int, vector <int> > pos;
int ind[Maxn];
iii lr[Maxn];
int BIT[Maxn];
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
		scanf("%d", &a[i]); ind[i] = pos[a[i]].size();
		pos[a[i]].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &lr[i].first.first, &lr[i].first.second); lr[i].second = i;
	}
	sort(lr, lr + m);
	for (map <int, vector <int> >::iterator it = pos.begin(); it != pos.end(); it++)
		if (it->second.size() >= it->first) {
			Insert(it->second[it->first - 1], 1);
			if (it->first < it->second.size()) Insert(it->second[it->first], -1);
		}
	int lst = 1;
	for (int i = 0; i < m; i++) {
		for (int j = lst; j < lr[i].first.first; j++)
			if (ind[j] + a[j] <= pos[a[j]].size()) {
				Insert(pos[a[j]][ind[j] + a[j] - 1], -1);
				if (ind[j] + a[j] < pos[a[j]].size()) Insert(pos[a[j]][ind[j] + a[j]], 1);
				if (ind[j] + 1 + a[j] <= pos[a[j]].size()) {
					Insert(pos[a[j]][ind[j] + a[j]], 1);
					if (ind[j] + 1 + a[j] < pos[a[j]].size()) Insert(pos[a[j]][ind[j] + 1 + a[j]], -1);
				}
			}
		lst = lr[i].first.first;
		res[lr[i].second] = Get(lr[i].first.second);
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", res[i]);
	return 0;
}