#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,iv=(mod+1)/2,maxn=1e6;
int n,m,ls[1111111],rs[1111111],sz[1111111],rd[1111111],rt,l,r,rt1,rt2,rt3,a[1111111],cnt,iv4,b[1111111];
int pw[333333],ipw[333333],val[1111111],pre[1111111],suf[1111111],res[1111111],ans,q,x,y;
int Get(int x)
{
	return ((rand()<<13)+rand())%x+1;
}
void pushup(int node)
{
	sz[node]=sz[ls[node]]+sz[rs[node]]+1;
	pre[node]=(1ll*val[node]*ipw[sz[rs[node]]]+1ll*pre[ls[node]]*ipw[sz[rs[node]]+1]+pre[rs[node]])%mod;
	suf[node]=(1ll*val[node]*ipw[sz[ls[node]]]+1ll*suf[rs[node]]*ipw[sz[ls[node]]+1]+suf[ls[node]])%mod;
	res[node]=(1ll*val[node]*pre[ls[node]]+1ll*val[node]*suf[rs[node]]+1ll*iv*pre[ls[node]]%mod*suf[rs[node]]+res[ls[node]]+res[rs[node]])%mod;
}
int merge(int x,int y)
{
	if (!x || !y) return x^y;
	if (rd[x]<=rd[y])
	{
		rs[x]=merge(rs[x],y);
		pushup(x);
		return x;
	}
	else
	{
		ls[y]=merge(x,ls[y]);
		pushup(y);
		return y;
	}
}
void split(int x,int &rt1,int &rt2,int y)
{
	if (!x) 
	{
		rt1=rt2=0;
		return;
	}
	if (y<=sz[ls[x]])
	{
		rt2=x;
		split(ls[x],rt1,ls[rt2],y);
		pushup(x);
	}
	else
	{
		rt1=x;
		split(rs[x],rs[rt1],rt2,y-sz[ls[x]]-1);
		pushup(x);
	}
}
void del(int x)
{
	int ps=rt,cs=0;
	while(ps)
	{
		if (val[ps]==x)
		{
			cs+=(sz[ls[ps]]);
			break;
		}
		if (val[ps]<x)
		{
			cs+=(sz[ls[ps]]+1);
			ps=rs[ps];
		}
		else
		{
			ps=ls[ps];
		}
	}
	split(rt,rt1,rt2,cs);
	split(rt2,rt2,rt3,1);
	rt=merge(rt1,rt3);
}
void add(int x)
{
	int ps=rt,cs=0;
	while(ps)
	{
		if (val[ps]<=x)
		{
			cs+=(1+sz[ls[ps]]);
			ps=rs[ps];
		}
		else ps=ls[ps];
	}
	split(rt,rt1,rt2,cs);
	++cnt;val[cnt]=pre[cnt]=suf[cnt]=x;
	rt=merge(rt1,cnt);rt=merge(rt,rt2);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	pw[0]=ipw[0]=1;
	for (int i=1;i<=n;i++)
	{
		pw[i]=(pw[i-1]+pw[i-1])%mod;
		ipw[i]=1ll*ipw[i-1]*iv%mod;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=maxn;i++)
	{
		rd[i]=i;
		sz[i]=1;
		if (i<=n) 
		{
			val[i]=a[i];
			pre[i]=suf[i]=a[i];
		}
	}
	cnt=n;
	random_shuffle(rd+1,rd+maxn+1);iv4=1ll*iv*iv%mod;
	for (int i=1;i<=n;i++)
	{
		rt=merge(rt,i);
	}
	printf("%d\n",1ll*res[rt]*iv4%mod);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		del(b[x]);
		b[x]=y;
		add(b[x]);
		printf("%d\n",1ll*res[rt]*iv4%mod);
	}
	return 0;
}