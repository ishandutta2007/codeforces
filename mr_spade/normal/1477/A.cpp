#include<cstdio>
#define int long long
inline int abs(int x)
{
	return x<0?-x:x;
}
inline int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
inline void solve()
{
	int n,k,t,x=0,y;
	register int i;
	scanf("%lld%lld%lld",&n,&k,&t);
	for(i=1;i<=n-1;i++)
		scanf("%lld",&y),x=gcd(x,abs(y-t));
	if(x==0)
		puts(k==t?"Yes":"No");
	else
		puts(abs(k-t)%x?"No":"Yes");
	return;
}
signed main()
{
	int T;
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}