#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,m,c,ans,dg[N];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		if(u>v) swap(u,v);++dg[u];
	}scanf("%d",&c);
	for(int i=1;i<=n;++i) if(!dg[i]) ++ans;
	for(int i=1,op,u,v;i<=c;++i)
	{
		scanf("%d",&op);
		if(op==3) {printf("%d\n",ans);continue;}
		scanf("%d %d",&u,&v);
		if(u>v) swap(u,v);
		if(op==1) {if(!dg[u]) --ans;++dg[u];}
		else {--dg[u];if(!dg[u]) ++ans;}
	}return 0;
}