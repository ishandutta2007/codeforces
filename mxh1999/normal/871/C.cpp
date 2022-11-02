#include<bits/stdc++.h>
using namespace std;

const int maxn=200010;
typedef long long ll;
const ll mo=1e9+7;
ll powmod(ll a,ll b)
{
	ll ans=1;
	while (b)
	{
		if (b&1)	ans=(ans*a)%mo;
		a=(a*a)%mo;
		b>>=1;
	}
	return ans;
}
struct St
{
	int x,y;
}	st[maxn];
int numx[maxn],numy[maxn];
int cntx,cnty;
int f[maxn],n;
int size[maxn],bian[maxn];

int fa(int t)
{
	if (f[t]==t)	return t;
	return f[t]=fa(f[t]);
}
void Union(int x,int y)
{
	x=fa(x);
	y=fa(y);
	if (x==y)
	{
		bian[x]++;
		return;
	}
	f[y]=x;
	size[x]+=size[y];
	bian[x]+=bian[y];
	bian[x]++;
	return;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		st[i].x=x;
		st[i].y=y;
		numx[++cntx]=x;
		numy[++cnty]=y;
	}
	sort(numx+1,numx+cntx+1);
	cntx=unique(numx+1,numx+cntx+1)-(numx+1);
	sort(numy+1,numy+cnty+1);
	cnty=unique(numy+1,numy+cnty+1)-(numy+1);
	for (int i=1;i<=cntx+cnty;i++)	f[i]=i,size[i]=1;
	for (int i=1;i<=n;i++)
	{
		st[i].x=lower_bound(numx+1,numx+cntx+1,st[i].x)-numx;
		st[i].y=lower_bound(numy+1,numy+cnty+1,st[i].y)-numy;
		Union(st[i].x,st[i].y+cntx);
	}
	long long ans=1;
	for (int i=1;i<=cntx+cnty;i++)
	if (f[i]==i)
	if (size[i]==bian[i]+1)
	{
		ll q=powmod(2,size[i]);
		q=(q-1+mo)%mo;
		ans=(ans*q)%mo;
	}	else
	{
		ll q=powmod(2,size[i]);
		ans=(ans*q)%mo;
	}
	printf("%I64d\n",ans);
	return 0;
}