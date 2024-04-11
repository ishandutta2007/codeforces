#include<bits/stdc++.h>
using namespace std;
long long n,m;
long double mx,mn,x,d,ans;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	mx=(long double)(n*(n-1)/2);
	if (n&1ll) mn=(long double)((n/2+1)*(n/2));
	else mn=(long double)((n/2+1)*(n/2)/2+(n/2)*(n/2-1)/2);
	for (long long i=1;i<=m;i++)
	{
		scanf("%Lf%Lf",&x,&d);
		ans+=x*(long double)n;
		if (d>0) ans+=mx*d;
		else ans+=mn*d;
	}
	printf("%.9Lf\n",ans/(long double)n);
	return 0;
}