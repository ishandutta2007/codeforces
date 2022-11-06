#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,p[N],ans;
deque<int> V;
inline void solve()
{
	register int i;
	scanf("%lld",&n);ans=0;
	V.clear();V.push_back(n);
	for(i=2;i<n;i++)
		if((i-1)*(i-1)>(n-i)*(n-i))
			V.push_front(i),ans+=(i-1)*(i-1);
		else
			V.push_back(i),ans+=(n-i)*(n-i);
	ans+=(n-1)*(n-1);
	V.push_front(1);
	for(i=0;i<n;i++)
		p[V[i]]=V[(i+1)%n];
	printf("%lld\n",ans);
	for(i=1;i<=n;i++)
		printf("%lld ",p[i]);
	putchar('\n');
	printf("%lld\n",n-1);
	for(i=2;i<n;i++)
		if((i-1)*(i-1)<=(n-i)*(n-i))
			printf("%lld %lld\n",i,n);
	for(i=n-1;i>=2;i--)
		if((i-1)*(i-1)>(n-i)*(n-i))
			printf("%lld %lld\n",i,1ll);
	printf("%lld %lld\n",1ll,n);
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