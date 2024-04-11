#include <bits/stdc++.h>
using namespace std;
#define N 135
#define ui unsigned int
ui n,m,c,ans,nw[N],C[N];
ui gcd(ui x,ui y) {return y?gcd(y,x%y):x;}
ui f1(ui x)
{
	ui res=1;for(ui i=1;i<=x;++i) nw[i]=i;
	for(ui i=n,t=i,d;i>n-x;--i,t=i)
	{for(ui j=1;j<=x;++j) d=gcd(t,nw[j]),t/=d,nw[j]/=d;res*=t;}
	return res;
}
ui f2(ui x)
{ui res=0;for(ui i=0,t=1;i<=m;++i,t*=x) res+=C[i]*t;return res;}
int main()
{
	scanf("%u %u %u",&n,&m,&c);m=min(m,n-1);
	for(ui i=0;i<=m;++i) C[i]=f1(i);
	for(ui i=1;i<=c;++i) ans^=i*f2(i);printf("%u\n",ans);return 0;
}