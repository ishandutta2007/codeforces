#include <bits/stdc++.h>
using namespace std;
#define N 105
#define ll long long
ll T,n,x,y,t1,t2,ans;
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld %lld %lld",&n,&x,&y);
		ans=(n+1>>1)/x*(x+y)+((n+1>>1)%x?(n+1>>1)%x:-y);
		printf("%lld\n",max(ans,n));
	}return 0;
}