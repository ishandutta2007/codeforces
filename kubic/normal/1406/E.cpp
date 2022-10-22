#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int n,x,lst,nw,p[N],st[N];ll ans=1;bool fl,vs[N],tg[N];
void sieve(int n)
{
	vs[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) p[++p[0]]=i;
		for(int j=1;i*p[j]<=n;++j)
		{vs[i*p[j]]=1;if(!(i%p[j])) break;}
	}
}
int main()
{
	scanf("%d",&n);sieve(n);
	for(int i=1;i<=p[0];++i)
	{
		if(!st[0] && 1ll*p[i]*p[i]>n) {lst=i;fl=1;break;}
		int cnt=0;
		for(int j=1;j*p[i]<=n;++j)
			if(!tg[j*p[i]]) ++cnt,tg[j*p[i]]=1;
		printf("B %d\n",p[i]);fflush(stdout);scanf("%d",&x);
		if(cnt<x) st[++st[0]]=p[i];
		if(!st[0] && 1ll*p[i]*p[i]<=n)
		{
			printf("A %d\n",p[i]);fflush(stdout);scanf("%d",&x);
			if(x) st[++st[0]]=p[i];
		}
	}
	if(fl)
	{
		int blk=sqrt(p[0]);
		printf("A 1\n");fflush(stdout);scanf("%d",&nw);
		for(int i=lst,L=lst,cnt=0;i<=p[0];++i)
		{
			++cnt;printf("B %d\n",p[i]);fflush(stdout);scanf("%d",&x);
			if(i/blk+1!=(i+1)/blk+1 || i==p[0])
			{
				printf("A 1\n");fflush(stdout);scanf("%d",&x);
				if(x>nw-cnt)
				{
					for(int j=L;j<=i;++j)
					{
						printf("A %d\n",p[j]);fflush(stdout);scanf("%d",&x);
						if(x) {ans=p[j];break;}
					}
				}L=i+1;if(ans>1) break;
			}
		}printf("C %lld\n",ans);return 0;
	}
	for(int i=1;i<=st[0];++i)
	{
		ans*=st[i];
		for(int j=1;ans<=n;++j,ans*=st[i])
		{
			printf("A %d\n",ans);fflush(stdout);scanf("%d",&x);
			if(!x) break;
		}ans/=st[i];
	}printf("C %lld\n",ans);fflush(stdout);return 0;
}