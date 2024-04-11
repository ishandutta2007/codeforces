#include<iostream>
#include<cstdio>
using namespace std;
int n,m,l[111111],r[111111],ans,cur;
int main()
{
	scanf("%d%d",&n,&m);
	ans=1e9;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		ans=min(ans,r[i]-l[i]+1);
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++)
	{
		printf("%d ",cur);
		cur=(cur+1)%ans;
	}
	printf("\n");
	return 0;
}