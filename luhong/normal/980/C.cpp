#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[101000];
int used[100100];
int main()
{
	int n,k;scanf("%d%d",&n,&k);memset(used,-1,sizeof(used));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int ok=-1;
		for(int j=a[i];j>=max(0,a[i]-k+1);j--)
		{
			if(used[j]!=-1)
			{
				if(used[j]>=a[i]-k+1)ok=used[j];
				else ok=j+1;
				break;
			}
		}
		if(ok==-1)ok=max(0,a[i]-k+1);
		for(int j=a[i];j>=ok;j--)used[j]=ok;
	}
	for(int i=1;i<=n;i++)printf("%d ",used[a[i]]);
	return 0;
}