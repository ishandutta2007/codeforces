#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#define re register
#define cmin(a,b) (a>(b)?a=(b):0)
#define cmax(a,b) (a<(b)?a=(b):0)
#define dmax(a,b) ((a)>(b)?(a):(b))
#define dmin(a,b) ((a)<(b)?(a):(b))
int a[100100];
int main()
{
	re int n,m,k;
	re double ans=0,num=0;
	scanf("%d%d%d",&n,&k,&m);
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);for(re int i=n;i>dmin(n,m+1);i--)num+=a[i];
	for(re int i=dmin(n,m+1);i;i--)
	{
		num+=a[i];
		cmax(ans,(num+dmin(m-i+1,(long long)(n-i+1)*k))/(n-i+1));
	}printf("%.15lf",ans);
}