#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=3e5+5;
int n;
int a[N],lst[N],mlen[N];
int ans[N];
inline void solve()
{
	register int i;
	scanf("%d",&n);
	memset(lst,0,sizeof(int)*(n+1));
	memset(mlen,0,sizeof(int)*(n+1));
	memset(ans,0x3f,sizeof(int)*(n+1));
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		mlen[a[i]]=std::max(mlen[a[i]],i-lst[a[i]]-1);
		lst[a[i]]=i;
	}
	for(i=1;i<=n;i++)
		mlen[i]=std::max(mlen[i],n-lst[i]),ans[mlen[i]+1]=std::min(ans[mlen[i]+1],i);
	for(i=2;i<=n;i++)
		ans[i]=std::min(ans[i],ans[i-1]);
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]==0x3f3f3f3f?-1:ans[i]);
	putchar('\n');
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}