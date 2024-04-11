#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 75
#define set(a,v) memset(a,v,sizeof(a))
#define ll long long
int T,n,ans,a[N],cnt[M];ll S;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;set(cnt,0);scanf("%lld %d",&S,&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),++cnt[(int)log2(a[i])];
		for(int i=0,t;i<64;++i)
		{
			if(S&(1ll<<i)) --cnt[i];
			if(cnt[i]<0) t=1-cnt[i]>>1,ans+=t,cnt[i+1]-=t,cnt[i]+=t<<1;
			cnt[i+1]+=cnt[i]>>1;cnt[i]=(cnt[i]>>1)<<1; 
		}if(cnt[64]<0) puts("-1");else printf("%d\n",ans);
	}return 0;
}