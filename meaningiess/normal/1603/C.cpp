#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int cnt[100010],a[100010];ll c[100010];
int s[1010];
int main()
{
	int T,i,j,n;cin>>T;
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		ll res=0;
		int top=1;s[1]=a[n];cnt[a[n]]=1;c[n]=0;
		for (i=n-1;i;i--)
		{
			int t1=0,t2=0,nw=0;c[i]=0;
			for (j=1;j<=top;j++) if (s[j]<a[i])
			{
				int tp=s[j],u=a[i]/((a[i]+tp-1)/tp);
				c[i]+=1ll*((a[i]+tp-1)/tp-1)*cnt[tp]%mod;c[i]%=mod;
				if (u==tp || !cnt[u]) s[++nw]=u;
				if (u!=tp) cnt[u]+=cnt[tp],cnt[tp]=0;
			}else break;
			for (;j<=top;j++) if (s[j]>a[i])
			{
				cnt[a[i]]+=cnt[s[j]];cnt[s[j]]=0;
			}
			s[++nw]=a[i];top=nw;
			cnt[a[i]]++;
		}
		for (i=n-1;i;i--) c[i]+=c[i+1],(res+=c[i])%=mod;
		printf("%lld\n",res);
		for (i=1;i<=top;i++) cnt[s[i]]=0;
	}
}