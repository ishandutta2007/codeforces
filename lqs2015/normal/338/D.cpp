#include<bits/stdc++.h>
using namespace std;
const long long inf=1e14;
long long aa[11111],bb[11111],mm[11111];
long long N,M,k,x[11111];
long long mul(long long a,long long b,long long mod)
{
	long long c=a*b-(long long)((long double)a*b/mod+0.5)*mod;
	if (c<0) c+=mod;
	return c;
} 
long long gcd(long long a,long long b)
{
    if (!b) return a;
    return gcd(b,a%b);
}
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long d=exgcd(b,a%b,x,y);
    long long t=x;
    x=y;
    y=t-a/b*y;
    return d;
}
long long inver(long long a,long long m)
{
    long long x,y;
    exgcd(a,m,x,y);
    return (m+x%m)%m;
}
pair<long long,long long> solve()
{
    long long x=0,m=1;
    for (long long i=1;i<=k;i++)
    {
        long long al=aa[i]*m,bl=bb[i]-aa[i]*x,d=gcd(mm[i],al);
        if (inf/m<mm[i]/d) return make_pair(-1,-1);
        if (bl%d!=0) return make_pair(-1,-1);
        long long t=mul(bl/d,inver(al/d,mm[i]/d),mm[i]/d);
        x=x+m*t;
        m*=(mm[i]/d);
    }
    return make_pair((x%m+m)%m,m);
}
int main()
{
	scanf("%lld%lld%lld",&N,&M,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%lld",&x[i]);
		aa[i]=1;bb[i]=((1-i)%x[i]+x[i])%x[i];mm[i]=x[i];
	}
	pair<long long,long long> nw=solve();
	if (nw.first==0) nw.first=nw.second;
	if (nw.second<0 || nw.second>N || nw.first>M-k+1) 
	{
		printf("NO\n");
		return 0;
	}
	for (long long i=nw.first,j=1;j<=k;j++,i++)
	{
		if (gcd(nw.second,i)!=x[j]) 
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}