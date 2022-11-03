#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;
const int sq = 550;

ll dp[maxn] , a[maxn] , ans[maxn];

int st[maxn] , d[maxn];

vector<int> sp[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		scanf("%d%d", &st[i], &d[i]);
		st[i]--;
		sp[d[i]].pb(i);
	}

	for(int i = 1; i <= n; i++)
	{
		if(i > sq)
			for(auto tmp : sp[i])
				for(int j = st[tmp]; j < n; j += i)
					ans[tmp] += a[j];
		else
		{
			for(int j = n - 1; j >= 0; j--)
			{
				dp[j] = a[j];
				if(j + i < n)
					dp[j] += dp[j + i];
			}
			for(auto tmp : sp[i])
				ans[tmp] = dp[st[tmp]];
		}
	}
	for(int i = 0; i < q; i++)
		printf("%I64d\n", ans[i]);
}