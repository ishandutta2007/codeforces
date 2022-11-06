#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
int a[1010000];
int main()
{
	int n,w;scanf("%d%d",&n,&w);
	int Max=-2e9,Min=2e9,sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];Max=max(Max,sum);Min=min(Min,sum);
	}
	printf("%d",max(0,min(w,w-Max)-max(-Min,0)+1));
	return 0;
}