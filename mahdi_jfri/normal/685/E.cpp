#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1.5e3 + 20;
const int maxm = 2e5 + 20;

vector<int> query[maxn] , qr[maxm];

int dp[maxn] , t[maxm] , l[maxm] , r[maxm] , from[maxm] , to[maxm];

bool ans[maxm];

int main()
{
	int n , m , q;
	scanf("%d%d%d" , &n, &m, &q);

	for(int i = 0; i < m; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		a-- , b--;

		from[i] = a , to[i] = b;
	}

	for(int i = 0; i < q; i++)
	{
		int s;
		scanf("%d%d%d%d", &s, &t[i], &l[i], &r[i]);
		s-- , t[i]-- , l[i]-- , r[i]--;

		swap(s , l[i]);
		swap(t[i] , r[i]);

		query[s].pb(i);
	}

	for(int s = 0; s < n; s++)
	{
		for(auto ind : query[s])
			qr[r[ind]].pb(ind);

		memset(dp , -1 , sizeof dp);

		for(int i = 0; i < m; i++)
		{
			dp[s] = i;

			dp[from[i]] = max(dp[from[i]] , dp[to[i]]);
			dp[to[i]] = dp[from[i]];

			for(auto ind : qr[i])
				if(l[ind] <= dp[t[ind]])
					ans[ind] = 1;
			qr[i].clear();
		}
	}

	for(int i = 0; i < q; i++)
	{
		if(ans[i])
			printf("Yes\n");
		else
			printf("No\n");
	}

}