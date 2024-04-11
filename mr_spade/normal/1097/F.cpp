#include<cstdio>
#include<cstring>
#include<bitset>
using std::bitset;
const int N=1e5+5,M=7005;
int n,m,bo;
int prime[N],tot;
bool isprime[N];
int mu[N];
inline void sieve(int n)
{
	register int i,j;
	memset(isprime+1,1,sizeof(bool)*n);
	isprime[1]=0;mu[1]=1;
	for(i=1;i<=n;i++)
	{
		if(isprime[i])
			prime[++tot]=i,mu[i]=1;
		for(j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			isprime[i*prime[j]]=0;
			if(i%prime[j]==0)
				break;
			mu[i*prime[j]]=mu[i];
		}
	}
	return;
}
bitset<M> d[M],u[M];
bitset<M> b[N];
signed main()
{
	int opt,x,y,z;
	register int i,j;
	sieve(7000);
	for(i=1;i<=7000;i++)
		for(j=1;i*j<=7000;j++)
			d[i*j][i]=1;
	for(i=1;i<=7000;i++)
		for(j=1;i*j<=7000;j++)
			u[i][i*j]=mu[j];
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&x,&y);
			b[x]=d[y];
		}
		else if(opt==2)
		{
			scanf("%d%d%d",&x,&y,&z);
			b[x]=b[y]^b[z];
		}
		else if(opt==3)
		{
			scanf("%d%d%d",&x,&y,&z);
			b[x]=b[y]&b[z];
		}
		else
		{
			scanf("%d%d",&x,&y);
			putchar((b[x]&u[y]).count()%2==1?'1':'0');
		}
	}
	putchar('\n');
	return 0;
}