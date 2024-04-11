#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 505
using namespace std;
int tot;
int n,m,cnt[N*N],a[N][N];
void ins(int x)
{
	tot-=!cnt[x];
	cnt[x]++;
}
void del(int x)
{
	cnt[x]--;
	tot+=!cnt[x];
}
void BellaKira()
{
	cin>>n>>m;
	int all=0;
	tot=0;
	for (int i=1;i<=n*n;i++) cnt[i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>a[i][j],all+=(!cnt[a[i][j]]),cnt[a[i][j]]++;
	if (all==m)
	{
		cout<<0<<'\n';
		return;
	}
	if (all<m)
	{
		cout<<m-all<<'\n';
		return;
	}
	int ans=2;
	for (int sum=2;sum<=2*n;sum++)
	{
		int l=0,r=n+1;
		for (int i=1;i<=n;i++)
			if (sum-i<=n&&sum-i>=1)
			{
				l=i;
				break;
			}
		for (int i=n;i>=1;i--)
			if (sum-i<=n&&sum-i>=1)
			{
				r=i;
				break;
			}
		// cout<<l<<" "<<r<<endl;
		int len=1,nowl=l;
		del(a[l][sum-l]);
		for (int i=l;i<=r;i++)
		{
			while (tot<all-m&&nowl<r)
			{
				len++;
				nowl++;
				for (int k=1,j=nowl;k<=len;k++,j--)
				{
					del(a[j][sum-nowl]);
				}
				ins(a[nowl][sum-nowl]);
				for (int k=1,j=sum-nowl;k<=len;k++,j++)
				{
					del(a[nowl][j]);
				}
			}
			if (tot==all-m||tot==all-m+1) 
			{
				// cout<<i<<" "<<sum-i<<" "<<nowl<<" "<<sum-nowl<<" "<<tot<<" "<<all<<endl;
				ans=1;
			}
			for (int k=1,j=i;k<=len;k++,j++)
			{
				ins(a[j][sum-i]);
			}
			del(a[i][sum-i]);
			for (int k=1,j=sum-i;k<=len;k++,j--)
			{
				ins(a[i][j]);
			}
			len--;
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}