#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,r[111111],c[111111],x,y,z,cnt,ans,pos;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	c[++n]=1000000000;
	sort(c+1,c+n+1);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if (x!=1) continue;
		r[++cnt]=y;
	}
	sort(r+1,r+cnt+1);
	pos=1;
	while(pos<=cnt && r[pos]<c[1]) pos++;
	ans=cnt-pos+1;
	for (int i=2;i<=n;i++)
	{
		while(pos<=cnt && r[pos]<c[i]) pos++;
		ans=min(ans,cnt-pos+i);
	}
	printf("%d\n",ans);
	return 0;
}