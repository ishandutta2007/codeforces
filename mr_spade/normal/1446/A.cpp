#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,W;
int w[N],p[N];
inline void solve()
{
	int sum=0;
	register int i,j;
	scanf("%lld%lld",&n,&W);
	for(i=1;i<=n;i++)
		scanf("%lld",&w[i]),p[i]=i;
	sort(p+1,p+n+1,[&](int x,int y)->bool
	{
		return w[x]<w[y];
	});
	for(i=1;i<=n;i++)
		if(sum+w[p[i]]<=W)
			sum+=w[p[i]];
		else if(sum>=(W+1)/2)
		{
			printf("%lld\n",i-1);
			for(j=1;j<=i-1;j++)
				printf("%lld ",p[j]);
			puts("");
			return;
		}
		else if(w[p[i]]<=W)
			return printf("%lld\n%lld\n",1ll,p[i]),void();
		else
			return puts("-1"),void();
	if(sum>=(W+1)/2)
	{
		printf("%lld\n",n);
		for(j=1;j<=n;j++)
			printf("%lld ",p[j]);
		puts("");
		return;
	}
	puts("-1");
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