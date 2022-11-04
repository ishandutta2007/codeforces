#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
const LL mod = 1e9+7;

int n , b[maxn] , bb , hh , a[20] , a1[20] , a2[20] , tp , p[maxn] , f[maxn] , gg , ans[maxn] , dp[20][(1<<18)] , re[2][20][(1<<18)] , sm , ss;
vector<int> v[maxn];
map<int,int> mp[2] , mmp[2];

void getv(int x)
{
	bb = b[x];
	for (int j = 1 ; j <= tp && p[j]*p[j] <= bb ; j++)
	{
		if (bb%p[j]) continue;
		v[x].push_back(p[j]);
		while (bb%p[j] == 0) bb /= p[j];
	}
	if (bb > 1) v[x].push_back(bb);
}

void getmp(int x , int t)
{
	for (auto i: v[x])
		if (!mp[t][i]) 
		{
			mp[t][i] = ++gg;
			mmp[t][i] = 1;
		}
}

void check(int i , int t)
{
	for (auto j: mp[t])
		if (mmp[t][j.first] && b[i]%j.first)
		{
			mmp[t][j.first]--;
			a[++hh] = i;
			break;
		}
}

int main()
{
	int t , i , j , x , y;
	srand(time(NULL));
	for (i = 2 ; i <= 40000 ; i++)
		if (!f[i])
		{
			p[++tp] = i;
			for (j = i+i ; j <= 40000 ; j += i)
				f[j] = 1;
		}
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&b[i]);
	t = 4;
	while (t--)
	{
		x = rand()%n+1;
		y = rand()%n+1;
		while (y == x) y = rand()%n+1;
		if (!(int)v[x].size()) getv(x);
		if (!(int)v[y].size()) getv(y);
		mp[0].clear();
		mp[1].clear();
		mmp[0].clear();
		mmp[1].clear();
		gg = 0;
		getmp(x,0);
		getmp(y,1);
		hh = 0;
		ss = (int)mp[0].size()+(int)mp[1].size();
		for (i = 1 ; i <= n ; i++)
		{
			if (i == x || i == y) continue;
			check(i,0);
			if (hh >= ss) break;
			if (a[hh] == i) continue;
			check(i,1);
			if (hh >= ss) break;
		}
		sm = (1<<ss)-1;
		for (i = 1 ; i <= hh ; i++)
		{
			a1[i] = sm;
			for (auto j: mp[0])
				if (b[a[i]]%j.first) a1[i] -= (1<<(j.second-1));
			a2[i] = sm;
			for (auto j: mp[1])
				if (b[a[i]]%j.first) a2[i] -= (1<<(j.second-1));
		}
		for (i = 0 ; i <= hh ; i++)
			for (j = 0 ; j <= sm ; j++)
				dp[i][j] = 0;
		dp[0][sm] = 1;
		for (i = 0 ; i < hh ; i++)
			for (j = 0 ; j <= sm ; j++)
			{
				if (!dp[i][j]) continue;
				dp[i+1][j&a1[i+1]] = 1;
				re[0][i+1][j&a1[i+1]] = 1;
				re[1][i+1][j&a1[i+1]] = j;
				dp[i+1][j&a2[i+1]] = 1;
				re[0][i+1][j&a2[i+1]] = 2;
				re[1][i+1][j&a2[i+1]] = j;
			}
		if (dp[hh][0])
		{
			cout << "YES\n";
			for (i = 1 ; i <= n ; i++)
				ans[i] = 1;
			ans[y] = 2;
			j = 0;
			for (i = hh ; i >= 1 ; i--)
			{
				if (re[0][i][j] == 2) ans[a[i]] = 2;
				j = re[1][i][j];
			}
			for (i = 1 ; i <= n ; i++)
				printf("%d ",ans[i]);
			cout << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}