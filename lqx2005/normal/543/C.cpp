#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=20;
ll n,m;
char a[N+5][N+5];
ll c[N+5][N+5];	
ll f[(1<<N)+5],l[(1<<N)+5];
ll s[N+5][N+5],t[N+5][N+5];
void checkmin(ll &x,ll y)
{
	if(x==-1||y<x) x=y;
	return;
}
ll lowbit(ll x)
{
	return x&(-x);
}
int main()
{
	for(ll i=1;i<=N;i++) l[(1<<i)]=i;
	memset(f,-1,sizeof(f));
	scanf("%lld%lld",&n,&m);
	for(ll i=0;i<n;i++) for(ll j=0;j<m;j++) cin>>a[i][j];
	for(ll i=0;i<n;i++) for(ll j=0;j<m;j++) scanf("%lld",&c[i][j]);
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			ll maxt=-1;
			for(ll k=0;k<n;k++)
			{
				if(a[i][j]==a[k][j])
				{
					maxt=max(maxt,c[k][j]);
					t[i][j]+=c[k][j];
					s[i][j]|=(1<<k);
				}
			}
			t[i][j]-=maxt;
		}
	}
	f[0]=0;
	ll full=(1<<n)-1;
	for(ll mask=0;mask<=full;mask++)
	{
		if(f[mask]==-1) continue;
		ll remask=full-mask;	
		ll now=lowbit(remask);
		now=l[now];
		if(remask==0) continue;		
		for(ll j=0;j<m;j++)
		{
			ll suba=mask+(1<<now);
			ll subb=mask|s[now][j];
			checkmin(f[subb],f[mask]+t[now][j]);
			checkmin(f[suba],f[mask]+c[now][j]);
		}
	}
	printf("%lld\n",f[full]);
	return 0;
}