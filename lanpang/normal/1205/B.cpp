#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , tp , ans , d[maxn];
LL a[maxn];
vector<int> v[maxn] , q;
struct mmp{
	int x , y;
}b[66];

int main()
{
	int i , j , la , x;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		scanf("%lld",&a[i]);
	for (j = 0 ; j < 60 ; j++)
	{
		la = 0;
		for (i = 1 ; i <= n ; i++)
		{
			if ((a[i]>>j)&1)
			{
				if (la == -1)
				{
					cout << "3\n";
					return 0;
				}
				if (la == 0) la = i;
				else
				{
					b[++tp].x = la;
					b[tp].y = i;
					v[la].push_back(i);
					v[i].push_back(la);
					la = -1;
				}
			}
		}
	}
	ans = n+1;
	for (j = 1 ; j <= tp ; j++)
	{
		for (i = 1 ; i <= n ; i++)
			d[i] = 0;
		d[b[j].x] = 1;
		q.clear();
		q.push_back(b[j].x);
		for (i = 0 ; i < q.size() ; i++)
		{
			x = q[i];
			for (auto to: v[x])
			{
				if ((x == b[j].x && to == b[j].y) || (x == b[j].y && to == b[j].x)) continue;
				if (!d[to])
				{
					d[to] = d[x]+1;
					q.push_back(to);
				}
			}
		}
		if (d[b[j].y]) ans = min(ans,d[b[j].y]);
	}
	if (ans == n+1) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}