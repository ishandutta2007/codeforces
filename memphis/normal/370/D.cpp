#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,m,i,j,k,u,d,l,r,ansu,ansd,ansl,ansr,tot;
int x[4000005],y[4000005];
char s[2005][2005];
bool ans;

void check(int u,int d,int l,int r)
{
	if(u<=0)return;
	if(d>n)return;
	if(l<=0)return;
	if(r>m)return;
	int i,j,k;
	for(k=1;k<=tot;++k)
	{
		i=x[k];j=y[k];
		if(i!=u&&i!=d&&j!=l&&j!=r)return;
		if(i<u||i>d||j<l||j>r)return;
	}
	ansu=u;
	ansd=d;
	ansl=l;
	ansr=r;
	ans=true;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	u=n;d=1;l=m;r=1;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	if(s[i][j]=='w')
	{
		++tot;
		x[tot]=i;
		y[tot]=j;
		if(i<u)u=i;
		if(i>d)d=i;
		if(j<l)l=j;
		if(j>r)r=j;
	}
	if(r-l>d-u)k=r-l;else k=d-u;
	ans=false;
	check(u,u+k,l,l+k);
	check(d-k,d,l,l+k);
	check(u,u+k,r-k,r);
	check(d-k,d,r-k,r);
	check(1,1+k,l,l+k);
	check(n-k,n,l,l+k);
	check(1,1+k,r-k,r);
	check(n-k,n,r-k,r);
	check(u,u+k,1,1+k);
	check(d-k,d,m-k,m);
	check(u,u+k,1,1+k);
	check(d-k,d,m-k,m);
	check(1,1+k,1,1+k);
	check(n-k,n,1,1+k);
	check(1,1+k,m-k,m);
	check(n-k,n,m-k,m);
	if(ans)
	{
		for(i=ansu;i<=ansd;++i)
		{
			if(s[i][ansl]=='.')s[i][ansl]='+';
			if(s[i][ansr]=='.')s[i][ansr]='+';
		}
		for(i=ansl;i<=ansr;++i)
		{
			if(s[ansu][i]=='.')s[ansu][i]='+';
			if(s[ansd][i]=='.')s[ansd][i]='+';
		}
		for(i=1;i<=n;++i)printf("%s\n",s[i]+1);
	}
	else printf("-1\n");
	//system("pause");
}