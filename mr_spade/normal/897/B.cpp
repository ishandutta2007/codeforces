#include<cstdio>
#define int long long
const int N(1e5+5);
int k,p,ans;
inline int count(int x)
{
	int base(x),res(0),rev(0);
	while(base)
	{
		rev=rev*10+base%10;
		base/=10;
		res++;
	}
	while(res--)
		x*=10;
	x+=rev;
	return x;
}
signed main()
{
	scanf("%I64d%I64d",&k,&p);
	for(int i=1;i<=k;i++)
		(ans+=count(i))%=p;
	printf("%I64d\n",ans);
	return 0;
}