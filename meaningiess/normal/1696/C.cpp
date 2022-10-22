#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,ll> a[50010],b[50010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,m,k,i,na=0,nb=0;cin>>n>>m;
		for (i=1;i<=n;i++)
		{
			int t;cin>>t;
			int nw=t,bs=1;
			while (nw%m==0) nw/=m,bs*=m;
			if (nw!=a[na].first)
			{
				na++;
				a[na]={nw,bs};
			}
			else a[na].second+=bs;
		}
		cin>>k;
		for (i=1;i<=k;i++)
		{
			int t;cin>>t;
			int nw=t,bs=1;
			while (nw%m==0) nw/=m,bs*=m;
			if (nw!=b[nb].first)
			{
				nb++;
				b[nb]={nw,bs};
			}
			else b[nb].second+=bs;
		}
		int flg=(na==nb);
		for (i=1;flg && i<=na;i++)  flg=(a[i]==b[i]);
		if (flg) puts("Yes");else puts("No");
	}
}