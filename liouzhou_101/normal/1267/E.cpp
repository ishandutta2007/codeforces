#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int maxV = 90010;
const int maxN = 2e2+10;
const int inf = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ll INF = 1000000000000000010LL;
#define X first
#define Y second


int a[maxN][maxN];
int b[maxN];
int tot = 0;
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=m;i++)
		{
			b[j] += a[i][j];
		}
	}
	int ans = inf;
	vector<int> res;
	for(int x=1;x<n;x++)
	{
		vector<pii> v;
		for(int i=1;i<=m;i++)
		{
			v.push_back(pii(a[i][n]-a[i][x],i));
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		int px = b[x];
		int py = b[n];
		vector<int> tmp;
		for(int i=0;i<m;i++)
		{
			if(px >= py)
			{
				break;
			}
			else
			{
				tmp.push_back(v[i].Y);
				px += v[i].X;
			}
		}
		if(tmp.size() < ans)
		{
			ans = tmp.size();
			res = tmp;
		}
	}
	printf("%d\n",ans);
	if(ans != 0)
	{
		int len = res.size();
		for(int i=0;i<len-1;i++)
		{
			printf("%d ",res[i]);
		}
		printf("%d\n",res[len-1]);
	}
	return 0;
}