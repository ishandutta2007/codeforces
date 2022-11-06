#include<cstdio>
#define int long long
int n;
inline int f(int x)
{
	int res=0;
	while(x)
		res+=x%10,x/=10;
	return res;
}
signed main()
{
	scanf("%lld",&n);
	if(n<9)
		return printf("%lld\n",n),0;
	int cur=9;
	while(1)
	{
		if(cur*10+9>n)
			return printf("%lld\n",f(cur)+f(n-cur)),0;
		cur=cur*10+9;
	}
	return 0;
}