#include <bits/stdc++.h>
using namespace std;
#define BU 5000
#define mod 1000000009
typedef vector<vector<long long> > matrix;
int a[300005],cnt[300005],cum[300005],cumf[300005];
vector<int> v[300005];
vector<pair<int,int> > upd;
matrix mmul(2,vector<long long>(2,0)),fib[300005];
void mul(matrix &a,matrix &b,matrix &c)
{
	for (int i=0;i<2;i++)
	{
		for (int x=0;x<2;x++)
		{
			mmul[i][x]=0;
			for (int j=0;j<2;j++)
			mmul[i][x]=(mmul[i][x]+a[i][j]*b[j][x])%mod;
		}
	}
	c=mmul;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	fib[0]={{1,1},{1,0}};
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mul(fib[0],fib[i-1],fib[i]);
		cumf[i]=(cumf[i-1]+fib[i][1][1])%mod;
	}
	for (int i=0;i<q;i++)
	{
		if (i%BU==0)
		{
			matrix cur({{0,0},{0,0}});
			for (int j=1;j<=n;j++)
			{
				while (cnt[j])
				{
					cnt[j]--;
					cur[0][0]++;
					cur[0][1]++;
					cur[1][0]++;
				}
				a[j]=(a[j]+cur[0][1])%mod;
				cum[j]=(a[j]+cum[j-1])%mod;
				for (int k:v[j])
				{
					cur[0][0]=(cur[0][0]-fib[j-k][0][0]+mod)%mod;
					cur[0][1]=(cur[0][1]-fib[j-k][0][1]+mod)%mod;
					cur[1][0]=(cur[1][0]-fib[j-k][1][0]+mod)%mod;
					cur[1][1]=(cur[1][1]-fib[j-k][1][1]+mod)%mod;
				}
				v[j].clear();
				mul(fib[0],cur,cur);
			}
			upd.clear();
		}
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if (t==1)
		{
			cnt[l]++;
			v[r].push_back(l);
			upd.push_back({l,r});
		}
		else
		{
			int ans=(cum[r]-cum[l-1]+mod)%mod;
			for (auto p:upd)
			{
				int fl=max(p.first,l)-p.first,fr=min(p.second,r)-p.first;
				if (fr<fl)
				continue;
				ans=(ans+cumf[fr+1])%mod;
				ans=(ans-cumf[fl]+mod)%mod;
			}
			printf("%d\n",ans);
		}
	}
}