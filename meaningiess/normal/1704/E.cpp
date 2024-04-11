#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
ll a[1010],na[1010],rd[1010],vis[1010];vector<int> e[1010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,flg=0;cin>>n>>m;
		for (i=1;i<=n;i++) {cin>>a[i];e[i].clear();rd[i]=0;vis[i]=0;}
		for (i=1;i<=m;i++)
		{
			int u,v;cin>>u>>v;
			e[u].push_back(v);rd[v]++;
		}
		ll ans=0;
		for (i=1;i<=n+2;i++)
		{
			int f=0;
			for (j=1;j<=n;j++) {na[j]=a[j];if (a[j]) f=1;}
			if (!f) {flg=1;break;}
			for (j=1;j<=n;j++) if (a[j])
			{
				na[j]--;f=1;
				for (auto p:e[j]) na[p]++;
			}
			for (j=1;j<=n;j++) a[j]=na[j];
			ans++;
		}
		if (flg)
		{
			cout<<ans%mod<<endl;continue;
		}
		ll res=0,s=0;
		for (i=1;i<=n;i++)
		{
			int p=0;
			for (j=1;j<=n;j++) if (!vis[j] && rd[j]==0) {p=j;break;}
			vis[p]=1;
			if (i==n) {res=a[p];break;}
			for (auto q:e[p]) (a[q]+=a[p])%=mod,rd[q]--;
		}
		cout<<(ans+res)%mod<<endl;
	}
}