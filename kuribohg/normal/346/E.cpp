#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int T;
LL a,n,p,h,ans;
LL work(LL a,LL n,LL p)
{
	if(a*n<p) return max(a,p-a*n);
	LL cnt=a*n/p;
	if(a*n%p<a*(p/a-1)) cnt--;
	return work(min(p%a,a-p%a),cnt,a);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d%I64d%I64d",&a,&n,&p,&h);
		a%=p;
		if(a*n<p) ans=a;
		else ans=work(a,n,p);
		if(ans>h) puts("NO");
		else puts("YES");
	}
	return 0;
}