#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxk = 43;

int rem[maxk] , g[maxk][maxk] , k[maxn] , ans[maxn] , t[maxk];

vector<pair<int , int> > pos[maxn] , a;

bool check(int k , int p)
{
	for(int i = 0; i < maxk; i++)
		if(t[i] && rem[i] % g[i][k] != p % g[i][k])
			return 0;

	return 1;
}

int main()
{
	int n , m;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < maxk; i++)
		for(int j = 0; j < maxk; j++)
			g[i][j] = __gcd(i , j);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &k[i]);
		int x;
		for(int j = 0; j < k[i]; j++)
			scanf("%d", &x) , pos[x - 1].pb({i , j});
	}

	for(int I = 0; I < m; I++)
	{
		if(pos[I].empty())
			continue;

		memset(t , 0 , sizeof t);
		memset(rem , -1 , sizeof rem);

		int n = pos[I].size();

		a = pos[I];

		int pt = 0;
		for(int i = 0; i < n; i++)
		{
			if(i && a[i].first != a[i - 1].first + 1)
			{
				memset(t , 0 , sizeof t);
				memset(rem , -1 , sizeof rem);
				pt = i;
			}

			int tmpk = k[a[i].first];

			while(pt < i && !check(tmpk , a[i].second))
			{
				int tmp = k[a[pt].first];
				t[tmp]--;

				if(!t[tmp])
					rem[tmp] = -1;
				pt++;
			}

			rem[tmpk] = a[i].second;
			t[tmpk]++;

			ans[I] = max(ans[I] , i - pt + 1);
		}
	}

	for(int i = 0; i < m; i++)
		printf("%d\n", ans[i]);

}