#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> v[1000001];
int degree[1000001];
int ans[1000001], layer[1000001];//anslayer
//truefalse
bool toposort(int n)
{
	int k = 0;
	memset(degree + 1, 0, sizeof(int)*n);
	memset(layer + 1, 0, sizeof(int)*n);
	for (int i = 1; i <= n; i++){
		for (unsigned int t = 0; t < v[i].size(); t++)
			degree[v[i][t]]++;
	}
	for (int i = 1; i <= n; i++){
		if (!degree[i])ans[k++] = i;
	}
	for (int j = 0; j < k; j++){
		for (unsigned int t = 0; t < v[ans[j]].size(); t++){
			int i = v[ans[j]][t];
			if (!--degree[i]){
				ans[k++] = i;
				layer[i] = layer[ans[j]] + 1;
			}
		}
	}
	return k == n;
}
#include<set>
#include<cstring>
using namespace std;
int a[200001], l[200001], r[200001];
int order[200001];
int cnum;
bool cmp(int i, int j){ return l[i] > l[j]; }
bool solve(int n)
{
	set<int> color;
	for (int t = n - 1; t >= 0; t--){
		int i = ans[t];
		l[i] = 1; r[i] = cnum;
		for (int j : v[i])
			l[i] = max(l[i], l[j] + 1);
		if (a[i] && a[i] < l[i])return false;
		l[i] = max(l[i], a[i]);
	}
	for (int i = 1; i <= cnum; i++)
		color.insert(i);
	for (int i = 1; i <= n; i++){
		color.erase(a[i]);
		order[i] = i;
	}
	sort(order + 1, order + n + 1, cmp);
	for (int k = 1; k <= n; k++){
		int i = order[k];
		if (r[i] < l[i])return false;
		if (!a[i]){
			auto it = color.upper_bound(r[i]);
			if (it == color.begin() || *--it < l[i])a[i] = r[i];
			else{
				a[i] = *it;
				color.erase(it);
			}
		}
		for (int j : v[i])
			r[j] = min(r[j], a[i] - 1);
	}
	return color.empty();
}
int main()
{
	int n, m, x, y;
	scanf("%d%d%d", &n, &m, &cnum);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i<m; i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}
	if (!toposort(n) || !solve(n))printf("-1");
	else for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
}