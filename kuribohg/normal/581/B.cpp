#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n,a[MAXN],Max,ans[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
	{
		if(a[i]>Max) Max=a[i],ans[i]=0;
		else ans[i]=Max+1-a[i];
	}
	for(int i=1;i<n;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return 0;
}