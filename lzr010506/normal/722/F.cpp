#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> mp;
#define pb push_back
const int NN = 200005;
const int M = 45;
const int N = 40;

vector<mp> rec[NN];

int GCD[M][M];
int val[M],lasl[M];
int n,m,cnt[NN];
int main()
{
	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= N; j ++)
			for (int k = 1; k <= N; k ++)
				if (i % k == 0 && j % k == 0) GCD[i][j] = k;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i ++) 
	{
		scanf("%d",&cnt[i]);
		for (int x, j = 0; j < cnt[i]; j ++) 
			scanf("%d",&x), rec[x].pb(mp(i,j));
	}

	for (int i = 1; i <= m; i ++) 
	{
		int ans = 0, las = -1, sum = 0, beg = -1;
		for (int j = 0; j < rec[i].size();j++) 
		{
			int pos = rec[i][j].first,sz = cnt[pos];
 			int mod = rec[i][j].second;
			if (pos != las + 1) 
			{
				sum = 1;
				beg = pos;
				for (int k = 1; k <= N; k ++) val[k] = -1;
			}
			else 
			{
				int maxlas = beg;
				for (int k = 1; k <= N; k ++)
				if (val[k]!=-1) 
				{
					int t = GCD[sz][k];
					if (val[k] % t != mod % t)
						maxlas=max(maxlas, lasl[k] + 1), val[k] = -1;
				}
				beg = maxlas;
				sum = pos - maxlas + 1;
			}
			ans = max(ans, sum);
			val[sz] = mod;
			lasl[sz] = las = pos;
		}
		printf("%d\n",ans);
	}
	return 0;
}