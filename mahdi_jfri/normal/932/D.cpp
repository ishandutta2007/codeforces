#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 4e5 + 20;
const int maxb = 20;

int mx[maxn][maxb] , par[maxn][maxb] , w[maxn] , f[maxn][maxb];

ll fs[maxn][maxb];

int main()
{
/*	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
*/
	for(int i = 1; i < maxb; i++)
		fs[1][i] = 1e18 , fs[0][i] = 1e18;

	fs[0][0] = 1e18;

	for(int i = 0; i < maxb; i++)
		par[1][i] = 1;
	int last = 0 , q , cnt = 2;
	cin >> q;

	while(q--)
	{
		ll type , p , q;
		scanf("%I64d%I64d%I64d", &type, &p, &q);
		ll R = (p ^ last) , W = (q ^ last);

		if(type == 1)
		{
			w[cnt] = W;

			par[cnt][0] = R;
			for(int i = 1; i < maxb; i++)
				par[cnt][i] = par[par[cnt][i - 1]][i - 1];

			mx[cnt][0] = W;
			for(int i = 1; i < maxb; i++)
				mx[cnt][i] = max(mx[cnt][i - 1] , mx[par[cnt][i - 1]][i - 1]);

			if(mx[R][maxb - 1] >= W)
			{
				int tmp = R;
				for(int i = maxb - 1; i >= 0; i--)
					if(mx[tmp][i] < W)
						tmp = par[tmp][i];
				if(w[tmp] >= W)
					f[cnt][0] = tmp;
				else
					f[cnt][0] = par[tmp][0];
			}
			else
				f[cnt][0] = 0;

			for(int i = 1; i < maxb; i++)
				f[cnt][i] = f[f[cnt][i - 1]][i - 1];

			fs[cnt][0] = W;

			for(int i = 1; i < maxb; i++)
			{
				if(fs[cnt][i - 1] >= 1e18)
					fs[cnt][i] = 1e18;
				else
					fs[cnt][i] = fs[cnt][i - 1] + fs[f[cnt][i - 1]][i - 1];
			}
			for(int i = 1; i < maxb; i++)
				if(fs[cnt][i] >= 1e18)
					fs[cnt][i] = 1e18;
			cnt++;
		}
		else
		{
			ll s = 0;
			int t = 0;
			for(int i = maxb - 1; i >= 0; i--)
				if(fs[R][i] + s <= W)
				{
					s += fs[R][i];
					t += (1 << i);
					R = f[R][i];
				}
			printf("%d\n", t);
			last = t;
		}
	}
}