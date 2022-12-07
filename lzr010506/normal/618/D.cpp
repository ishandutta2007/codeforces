#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#define N 200010
using namespace std;
vector<int> map[N];
int ss = 0, a ,b, tree;

int dfs(int u, int fa)
{
	int s = 2;
    for (int i = 0; i < map[u].size(); i++)
	{
        int v = map[u][i];
        if (v == fa) continue;
        if (dfs(v, u) && s)
            ss ++, s --;
    }
    return s;
}
int main()
{
	long long x,y;
	int n,a,b,i;
	scanf("%d %I64d %I64d", &n, &x, &y);
	for(int i = 1; i < n; i ++)
	{
		scanf("%d%d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	
	if(x <= y) dfs(1,-1);
	else 
		for (int i = 1; i <= n; i ++)
            if (map[i].size() == n - 1)
			{
                ss ++;
                break;
            }
	
	printf("%I64d", x * ss + y * (n - ss - 1));
	
	return 0;
}