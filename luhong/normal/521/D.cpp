#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#define MN 101000

typedef long long ll;
ll a[MN];
int Max[MN], id[MN];
int t[MN], p[MN], w[MN];

struct xxx {
	double x; int id, t;
	xxx(){}
	xxx(double a, int b, int c) {x = a; id = b; t = c;}
} ans[MN];

int tot = 0;

struct xxx2{
	int x; int id, t;
	xxx2(){}
	xxx2(int a, int b, int c) {x = a; id = b; t = c;}
};

#define eps 1e-10

bool cmp(xxx a, xxx b) {return a.x > b.x;}
bool cmp2(xxx2 a, xxx2 b) {return a.x > b.x;}
bool cmp3(xxx a, xxx b) {return a.t < b.t;}

std::vector<xxx2> v[MN];

int main()
{
	int k, n, m; scanf("%d%d%d", &k, &n, &m);
	for(int i = 1; i <= k; i++) scanf("%lld", &a[i]), Max[i] = a[i];
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &t[i], &p[i], &w[i]);
		if(t[i] == 1)
		{
			if(w[i] > Max[p[i]]) Max[p[i]] = w[i], id[p[i]] = i;			
		}
	}
	for(int i = 1; i <= k; i++)
		if(id[i]) v[i].push_back(xxx2(Max[i] - a[i], id[i], 1));
	for(int i = 1; i <= n; i++)
	{
		if(t[i] == 2) v[p[i]].push_back(xxx2(w[i], i, 2));
		if(t[i] == 3) ans[++tot] = xxx(w[i], i, 3);
	}
	for(int i = 1; i <= k; i++)
	{
		std::sort(v[i].begin(), v[i].end(), cmp2);
		for(int j = 0; j < v[i].size(); j++) 
		{
			ans[++tot] = xxx(1.0 * (a[i] + v[i][j].x) / a[i], v[i][j].id, v[i][j].t);
			a[i] += v[i][j].x;
		}
	}
	std::sort(ans + 1, ans + tot + 1, cmp);
	
	int M = std::min(tot, m);
	printf("%d\n", M);
	std::sort(ans + 1, ans + M + 1, cmp3);
	for(int i = 1; i <= M; i++) printf("%d ", ans[i].id);
}