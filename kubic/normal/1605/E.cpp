#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
int n,m,tp,cnt,p[N],mu[N],a[N],b[N];
ll ans,w[N],st[N],s[N];bool vs[N];
void sieve(int n)
{
	mu[1]=vs[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) p[++p[0]]=i,mu[i]=-1;
		for(int j=1;i*p[j]<=n;++j)
		{
			vs[i*p[j]]=1;mu[i*p[j]]=-mu[i];
			if(!(i%p[j])) {mu[i*p[j]]=0;break;}
		}
	}
}
int main()
{
	scanf("%d",&n);sieve(n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	scanf("%d",&m);b[1]=0;
	for(int i=1;i<=n;++i) for(int j=i;j<=n;j+=i)
		w[j]+=(b[i]-a[i])*mu[j/i];
	for(int i=1;i<=n;++i)
	{
		ans+=abs(w[i]);if(mu[i]<0) w[i]=-w[i];
		if(mu[i]) {if(w[i]<0) st[++tp]=w[i];else ++cnt;}
	}sort(st+1,st+tp+1);
	for(int i=tp;i;--i) s[i]=s[i+1]+st[i];
	for(int i=1,x,t;i<=m;++i)
	{
		scanf("%d",&x);
		t=lower_bound(st+1,st+tp+1,-x)-st-1;
		printf("%lld\n",ans+1ll*(cnt+tp-t*2)*x+s[t+1]*2);
	}return 0;
}