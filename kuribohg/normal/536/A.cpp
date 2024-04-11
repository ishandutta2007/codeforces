#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
int n;
LL A,B;
LL l,t,m;
LL L,R,mid;
LL f(LL x)
{
	return A+(x-1LL)*B;
}
LL S(LL a,LL b,LL k)
{
	return (a+b)*k/2LL;
}
int main()
{
	scanf("%I64d%I64d%d",&A,&B,&n);
	while(n--)
	{
		scanf("%I64d%I64d%I64d",&l,&t,&m);
		if(f(l)>t) {puts("-1");continue;}
		L=0;
		R=2000000;
		while(L<R)
		{
			bool ok=true;
			mid=(L+R+1)>>1;
			LL r=l+mid;
			if(f(r)>t) ok=false;
			if(S(f(l),f(r),r-l+1)>m*t) ok=false;
			if(ok) L=mid;
			else R=mid-1;
		}
		printf("%d\n",l+L);
	}
	return 0;
}