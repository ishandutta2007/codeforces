#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

LL n , dp[maxn] , ans , s[maxn] , tp , t;
vector<int> v[maxn];
struct mmp{
	LL k , b;
	bool operator < (const mmp &op) const{
		return k < op.k;
	}
}q[maxn] , qq[maxn];

LL chk(mmp x , mmp y)
{
	return (n*(n-1)+x.k*y.k*2+x.b+y.b)/2;
}

bool cmp(mmp x , mmp y , mmp z)
{
	return (x.b-z.b)*(y.k-x.k) <= (x.b-y.b)*(z.k-x.k);
}

void dfs(int x , int y)
{
	s[x] = 1;
	for (auto to: v[x])
		if (to != y) 
		{
			dfs(to,x);
			s[x] += s[to];
		}
	dp[x] = s[x]*(s[x]-1)/2;
	tp = 0;
	for (auto to: v[x])
		if (to != y) 
		{
			dp[x] = min(dp[x],dp[to]+(s[x]-s[to])*(s[x]-s[to]-1)/2);
			ans = min(ans,dp[to]+(n-s[to])*(n-s[to]-1)/2);
			q[++tp] = {s[to],s[to]*s[to]-(n*2-1)*s[to]+dp[to]*2};
		}
	if (tp >= 2)
	{
		sort(q+1,q+tp+1);
		t = 0;
		qq[++t] = q[1];
		for (int i = 2 ; i <= tp ; i++)
		{
			while (t >= 2 && chk(q[i],qq[t]) >= chk(q[i],qq[t-1])) t--;
			ans = min(ans,chk(q[i],qq[t]));
			qq[++t] = q[i];
			while (t >= 3 && cmp(qq[t],qq[t-1],qq[t-2]))
			{
				swap(qq[t],qq[t-1]);
				t--;
			}
		}
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
	ans = n*(n-1);
	dfs(1,0);
	cout << n*(n-1)-ans << "\n";
	return 0;
}