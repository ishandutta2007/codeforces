#include<cstdio>
#include<iostream>

using namespace std;

const int MaxLen=3000010;
const int MaxN=5010;

char s[MaxLen],ans[MaxLen];

int k,n;
int x[MaxN],y[MaxN];

int v[MaxLen],F[MaxLen];

void init()
{
	scanf("%s%d%d",s+1,&k,&n);
	for (int i=1;i<=n;++i)
		scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=k;++i)
		v[i]=i&-i;
}

void del(int x)
{
	for (;x<=k;x+=x&-x)
		--v[x];
}

int find(int x)
{
	int p=0;
	for (int i=1<<21;i;i>>=1)
		if (p+i<=k) if (v[p+i]<x)
			x-=v[p+=i];
	return p+1;
}

void work()
{
	int have=k;
	for (int i=n;i>=1;--i)
	{
		for (int p=x[i]+1,c=1;c<=y[i]-x[i]+1&&y[i]<have;p+=2,++c)
		{
			if (p>y[i]) p=x[i];
			--have;
			int way=find(y[i]+1);
			del(way);
			F[way]=find(p);
		}
	}
	for (int i=1,j=0;i<=k;++i)
		ans[i]=(F[i])?ans[F[i]]:s[++j];
	puts(ans+1);
}

int main()
{
	init();
	work();
	return 0;
}