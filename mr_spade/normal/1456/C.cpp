#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
using std::sort;
using std::priority_queue;
const int N=5e5+5;
int n,k,ans;
int a[N];
priority_queue<int> Q;
signed main()
{
	int x;
	register int i;
	scanf("%lld%lld",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1,[](int a,int b)->bool
	{
		return a>b;
	});
	for(i=1;i<=k+1;i++)
		Q.push(0);
	for(i=1;i<=n;i++)
	{
		x=Q.top();Q.pop();
		ans+=x;Q.push(x+a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}