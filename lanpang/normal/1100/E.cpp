#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , m , du[maxn] , id[maxn];
vector<int> v[maxn] , w[maxn] , g[maxn] , q;

bool check(int x)
{
	int i , j;
	for (i = 1 ; i <= n ; i++)
		du[i] = 0;
	for (i = 1 ; i <= n ; i++)
		for (j = 0 ; j < v[i].size() ; j++)
			if (w[i][j] > x) du[v[i][j]]++;
	q.clear();
	for (i = 1 ; i <= n ; i++)
		if (du[i] == 0) q.push_back(i);
	for (i = 0 ; i < q.size() ; i++)
	{
		for (j = 0 ; j < v[q[i]].size() ; j++)
		{
			if (w[q[i]][j] > x)
			{
				du[v[q[i]][j]]--;
				if (du[v[q[i]][j]] == 0) q.push_back(v[q[i]][j]);
			}
		}
	}
	if (q.size() < n) return false;
	else return true;
}

void print(int x)
{
	int i , j;
	for (i = 1 ; i <= n ; i++)
		du[i] = 0;
	for (i = 1 ; i <= n ; i++)
		for (j = 0 ; j < v[i].size() ; j++)
			if (w[i][j] > x) du[v[i][j]]++;
	q.clear();
	for (i = 1 ; i <= n ; i++)
		if (du[i] == 0) q.push_back(i);
	for (i = 0 ; i < q.size() ; i++)
	{
		id[q[i]] = i+1;
		for (j = 0 ; j < v[q[i]].size() ; j++)
		{
			if (w[q[i]][j] > x)
			{
				du[v[q[i]][j]]--;
				if (du[v[q[i]][j]] == 0) q.push_back(v[q[i]][j]);
			}
		}
	}
	q.clear();
	for (i = 1 ; i <= n ; i++)
		for (j = 0 ; j < v[i].size() ; j++)
			if (w[i][j] <= x && id[i] > id[v[i][j]]) q.push_back(g[i][j]);
	sort(q.begin(),q.end());
	cout << x << " " << q.size() << "\n";
	for (auto i: q)
		printf("%d ",i);
	cout << "\n";
}

int main()
{
	int i , j , x , y , z , l , r , mid;
	cin >> n >> m;
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(y);
		w[x].push_back(z);
		g[x].push_back(i);
	}
	l = 0;
	r = 1000000000;
	while (l <= r)
	{
		mid = (l+r)/2;
		if (check(mid)) r = mid-1;
		else l = mid+1;
	}
	print(l);
	return 0;
}