#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100000;
int n,m;
int x[maxn+5],d[maxn+5],disa=0,disb=0;
int Abs(int x)
{
	if(x<0) return -x;
	return x;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++) scanf("%lld%lld",&x[i],&d[i]);
	for(int i=1;i<=n;i++)
	{
		disa+=Abs(i-1);
		disb+=Abs(i-(n+1)/2);
	}
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		if(d[i]<=0) sum+=x[i]*n+disb*d[i];
		else sum+=x[i]*n+disa*d[i];
	}
	printf("%.10lf\n",(double)sum/(double)n);
	return 0;
}