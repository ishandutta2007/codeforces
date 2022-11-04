#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 998244353;

int n;
vector<int> v[maxn];
LL ans = 1 , jc[maxn];

void dfs(int x , int y)
{
	int f = 0;
	for (auto to: v[x])
	{
		if (to != y)
		{
			dfs(to,x);
			f++;
		}
	}
	ans = ans*jc[f]%mod*(x==1?n:(f+1))%mod;
}

int main()
{
	int i , j , x , y;
	cin >> n;
	jc[0] = 1;
	for (i = 1 ; i <= n ; i++)
		jc[i] = jc[i-1]*i%mod;
	for (i = 1 ; i < n ; i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	cout << ans << "\n";
	return 0;
}