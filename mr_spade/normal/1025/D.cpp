#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<cstring>
#include<algorithm>
using std::__gcd;
using std::sort;
const int N=705;
int n;
int a[N];
int memo[N][N][2];
int f(int l,int r,int t)
{
	if(l>r)
		return 1;
	if(~memo[l][r][t])
		return memo[l][r][t];
	register int i;
	for(i=l;i<=r;i++)
		if(__gcd(a[i],t?a[l-1]:a[r+1])!=1&&f(l,i-1,0)&&f(i+1,r,1))
			return memo[l][r][t]=1;
	return memo[l][r][t]=0;
}
signed main()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	memset(memo,-1,sizeof(memo));
	for(i=1;i<=n;i++)
		if(f(1,i-1,0)&&f(i+1,n,1))
			return puts("Yes"),0;
	puts("No");
	return 0;
}