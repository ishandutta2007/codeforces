#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=1e5;
int n,k,cnt[111111],a[111111],mxx,prime[111111],ct,mx[111111],cnr;
long long cur,ans,ts,fuck,fk;
bool f,fl[111111];
void Init()
{
	for (int i=2;i<=maxn;i++)
	{
		if (!fl[i])
		{
			prime[++ct]=i;
		}
		for (int j=1;j<=ct && i*prime[j]<=maxn;j++)
		{
			fl[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
	for (int i=1;i<=ct;i++)
	{
		for (int j=prime[i];j<=maxn;j+=prime[i])
		{
			mx[j]=i;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) cnt[a[i]]++;
	for (int i=2;i<=maxn;i++)
	{
		cur=1;
		for (int j=1;j<=k;j++)
		{
			if (cur>100000)
			{
				f=1;
				break;
			}
			cur=cur*i;
		}
		if (cur>100000)
		{
			mxx=i-1;
			break;
		}
	}
	Init();
	for (int i=1;i<=n;i++)
	{
		cur=a[i];fuck=1;
		while(cur>1)
		{
			int x=mx[cur];cnr=0;
			while(cur%prime[x]==0)
			{
				cnr++;
				cur/=prime[x];
			}
			cnr=(cnr-1)%k+1;
			for (int j=1;fuck!=-1 && j<=k-cnr;j++)
			{
				fuck*=prime[x];
				if (fuck>maxn) fuck=-1;
			}
		}
		if (fuck==-1) continue;
		for (int j=1;j<=mxx;j++)
		{
			fk=fuck;
			for (int h=1;fk!=-1 && h<=k;h++)
			{
				fk*=j;
				if (fk>maxn) fk=-1;
			}
			if (~fk)
			{
				if (fk==a[i]) ans+=(cnt[fk]-1);
				else ans+=cnt[fk];
			}
			else break;
		}
	}
	printf("%lld\n",ans/2);
	return Accepted;
}