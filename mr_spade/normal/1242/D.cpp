#include<cstdio>
#define int long long
int n,k;
inline int I(int n)
{
	if(n==0)
		return k*(k+1)/2;
	int i=n/k,t=n%k;
	int pre=I(i),offset;
	if(pre>i*(k*k+1)+(t+1)*k)
		offset=0;
	else if(pre<=i*(k*k+1)+t*k)
		offset=k;
	else
		offset=i*(k*k+1)+(t+1)*k-pre+1;
	return (i*k+t)*(k*k+1)-t+k*(k+1)/2+offset;
}
inline void solve()
{
	scanf("%lld%lld",&n,&k);
	int t=(n-1)/(k*k+1);
	int res=I(t);
	if(res==n)
		printf("%lld\n",(t+1)*(k+1));
	else if(res>n)
		printf("%lld\n",t*k*(k+1)+(n-t*(k*k+1))+(n-1-t*(k*k+1))/k);
	else
		printf("%lld\n",t*k*(k+1)+(n-1-t*(k*k+1))+(n-2-t*(k*k+1))/k);
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