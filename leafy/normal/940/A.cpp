#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,d;
int x[105],a[105];
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	sort(x+1,x+n+1);
	int k,l,ans=n-1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(x[j]-x[i]>d) break;
			ans=min(ans,n-(j-i+1));
		}
	printf("%d",ans);
	return 0;
}