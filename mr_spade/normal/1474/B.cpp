#include<cstdio>
#include<algorithm>
#define int long long
using std::min;
inline bool isprime(int x)
{
	register int i;
	for(i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
inline int find(int x)
{
	while(!isprime(x))
		x++;
	return x;
}
inline void solve()
{
	int d,p1,p2,x1,x2;
	scanf("%lld",&d);
	p1=find(d+1);p2=find(p1+d);
	printf("%lld\n",min(p1*p2,p1*p1*p1));
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