#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n,m;
LL x[5010],ans[5010];
LL op[5010],l[5010],r[5010],d[5010];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%I64d%I64d%I64d%I64d",&op[i],&l[i],&r[i],&d[i]);
	for(int i=1;i<=n;i++) x[i]=1000000000;
	for(int i=1;i<=n;i++)
	{
		LL delta=0;
		for(int j=1;j<=m;j++)
		{
			if(op[j]==1)
			{
				if(l[j]<=i&&i<=r[j]) delta+=d[j];
				else continue;
			}
			else
			{
				if(l[j]<=i&&i<=r[j]) x[i]=min(x[i],d[j]-delta);
				else continue;
			}
		}
	}
	for(int i=1;i<=n;i++) ans[i]=x[i];
	for(int i=1;i<=n;i++) if(ans[i]<-1000000000) {puts("NO");return 0;}
	for(int i=1;i<=m;i++)
	{
		LL con=-1000000000000000000LL;
		for(int j=l[i];j<=r[i];j++)
		{
			if(op[i]==1) x[j]+=d[i];
			else con=max(con,x[j]);
		}
		if(op[i]==2&&con!=d[i]) {puts("NO");return 0;}
	}
	puts("YES");
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}