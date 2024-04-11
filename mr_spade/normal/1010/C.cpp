#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using std::swap;
using std::set;
inline int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
const int N=4e5+5;
int n,m,k;
signed main()
{
	int x,ans=0;
	register int i,j;
	scanf("%d%d",&n,&k);m=k;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		m=gcd(m,x%k);
	}
	for(i=0;i<k;i+=m)
		ans++;
	printf("%d\n",ans);
	for(i=0;i<k;i+=m)
		printf("%d ",i);
	putchar('\n');
	return 0;
}