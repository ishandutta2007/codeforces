#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n,a[2010],c[10010];
LL d[10010];
double ans,S;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			c[a[j]-a[i]]++;
	for(int i=1;i<=5000;i++)
		for(int j=1;j<=5000;j++)
			d[i+j]+=(LL)c[i]*c[j];
	for(int i=5000;i>=1;i--) c[i]+=c[i+1];
	S=n*(n-1)/2;
	S=S*S*S;
	for(int i=1;i<=5000;i++)
		ans+=(double)d[i]*c[i+1]/S;
	printf("%.010lf\n",ans);
	return 0;
}