
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n,k;bool ac=1;int tot=0,head=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			tot++;
		}
	}
	if(tot<=k&&tot!=1)
	{
		printf("Yes");
		return 0;
	}
	sort(b+1,b+k+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			a[i]=b[++head];
		}
		if(a[i]<a[i-1])
		{
			printf("Yes");
			return 0;
		}
		if(head>k)
		{
			printf("No");
			return 0;
		}
	}
	printf("No");
	return 0;
}