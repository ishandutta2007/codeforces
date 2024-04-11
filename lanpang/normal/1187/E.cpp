#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , s[maxn];
vector<int> v[maxn];
LL ans , sum;

void dfs(int x , int y)
{
	s[x] = 1;
	for (auto to: v[x])
		if (y != to) 
		{
			dfs(to,x);
			s[x] += s[to];
		}
	sum += s[x];
}

void jisuan(int x , int y)
{
	ans = max(ans,sum);
	for (auto to: v[x])
		if (y != to) 
		{
			sum += n-s[to]*2;
			jisuan(to,x);
			sum -= n-s[to]*2;
		}
}

int main()
{
	int i , j , x , y;
	cin >> n;
	for (i = 1 ; i < n ; i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	jisuan(1,0);
	cout << ans << "\n";
	return 0;
}