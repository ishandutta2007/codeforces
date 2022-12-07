#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
typedef long long LL;
int n,m;
LL a[100010],b[100010],sa[100010],sb[100010],ans=LONG_LONG_MAX;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%I64d",&b[i]);
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	for(int i=1;i<=n;i++) sa[i]=sa[i-1]+a[i];
	for(int i=m;i>=1;i--) sb[i]=sb[i+1]+b[i];
	for(int i=1;i<=n;i++)
	{
		int sub=upper_bound(b+1,b+m+1,a[i])-b;
		LL p=(i-1)*a[i]-sa[i-1]+sb[sub]-(m+1-sub)*a[i];
		ans=min(ans,p);
	}
	for(int j=1;j<=m;j++)
	{
		int sub=upper_bound(a+1,a+n+1,b[j])-a;
		LL p=(sub-1)*b[j]-sa[sub-1]-(m-j)*b[j]+sb[j+1];
		ans=min(ans,p);
	}
	printf("%I64d\n",ans);
	return 0;
}