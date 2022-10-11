#include <iostream>
#include <string.h>
using namespace std;
int cnt[1024],tmp[1024];
int main()
{
	int n,k,x;
	scanf("%d%d%d",&n,&k,&x);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	while (k--)
	{
		memset(tmp,0,sizeof(tmp));
		bool cur=1;
		for (int i=0;i<1024;i++)
		{
			int t=cnt[i]/2+(cnt[i]%2 && cur);
			cur^=(cnt[i]%2);
			tmp[i]+=cnt[i]-t;
			tmp[i^x]+=t;
		}
		for (int i=0;i<1024;i++)
		cnt[i]=tmp[i];
	}
	int mx=0,mn=1024;
	for (int i=0;i<1024;i++)
	{
		if (cnt[i])
		{
			mx=i;
			mn=min(mn,i);
		}
	}
	printf("%d %d",mx,mn);
}