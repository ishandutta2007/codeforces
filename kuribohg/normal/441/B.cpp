#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<utility>
using namespace std;
int n,m,ans,a[3010],in1,in2;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&in1,&in2);
		a[in1]+=in2;
	}
	for(int i=1;i<=3001;i++)
	{
		if(a[i-1]>=m) {ans+=m,a[i-1]-=m;continue;}
		else
		{
			int p=m-a[i-1];
			ans+=a[i-1];
			a[i-1]=0;
			ans+=min(p,a[i]);
			a[i]-=min(p,a[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}