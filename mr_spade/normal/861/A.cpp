#include<cstdio>
#define int long long
const int N=1e9+5;
int n,k;
int m(int x)
{
	while(!(x%10))
		x/=10;
		int i=x%10;
	if(i%2==0)
		return 2;
	if(i==5)
		return 5;
	return 1;
}
int f(int x)
{
	int cnt=0;
	while(!(x%10))
	{
		x/=10;
		cnt++;
	}
	return cnt;
}
signed main()
{
	int i,j;
	scanf("%I64d%I64d",&n,&k);
	while(f(n)<k)
		n*=10/m(n);
	printf("%I64d\n",n);
}