#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
const int all=(1<<18)-1;
int n,cnt[N],fa[N];ll ans;
int findRt(int u) {return u==fa[u]?u:fa[u]=findRt(fa[u]);}
bool merge(int u,int v)
{u=findRt(u);v=findRt(v);if(u==v) return 0;fa[u]=v;return 1;}
int main()
{
	scanf("%d",&n);cnt[0]=1;for(int i=0;i<=all;++i) fa[i]=i;
	for(int i=1,x;i<=n;++i) scanf("%d",&x),++cnt[x],ans-=x;
	for(int i=all;i;--i) for(int j=i;j*2>i;j=j-1&i)
		if(cnt[j] && cnt[i^j] && merge(j,i^j))
			ans+=1ll*i*(cnt[j]+cnt[i^j]-1),cnt[j]=cnt[i^j]=1;
	printf("%lld\n",ans);return 0;
}