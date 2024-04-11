#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
#define pb push_back
const int lim=1e5;
int n,a[N],cnt[N],p[N],mu[N];vector<int> d[N];ll ans;bool vs[N],tg[N];
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
void sieve(int n)
{
	mu[1]=vs[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) p[++p[0]]=i,mu[i]=-1;
		for(int j=1;i*p[j]<=n;++j)
		{vs[i*p[j]]=1;if(!(i%p[j])) break;mu[i*p[j]]=-mu[i];}
	} 
}
void upd(int x,int w) {for(auto i:d[x]) cnt[i]+=w;}
int qry(int x) {int res=0;for(auto i:d[x]) res+=cnt[i]*mu[i];return res;}
int main()
{
	scanf("%d",&n);sieve(lim);
	for(int i=1;i<=lim;++i) for(int j=i;j<=lim;j+=i) d[j].pb(i);
	for(int i=1,x;i<=n;++i) {scanf("%d",&x);for(auto j:d[x]) tg[j]=1;}
	n=0;for(int i=1;i<=lim;++i) if(tg[i]) a[++n]=i;ans=a[n];
	for(int i=1;i<=n;++i) upd(a[i],1);
	for(int i=n,t=1,t1;i;--i)
	{
		t1=qry(a[i]);if(!t1) continue;
		while(t<=n && t1) upd(a[t],-1),t1-=(gcd(a[i],a[t])<2),++t; 
		ans=max(ans,1ll*a[i]*a[t-1]);
	}printf("%lld\n",ans);return 0;
}