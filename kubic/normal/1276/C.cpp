#include <bits/stdc++.h>
using namespace std;
#define N 400005
int n,ans,ps,a[N],ds[N],cnt[N],ord[N],st[N];
bool cmp(int x,int y) {return cnt[x]<cnt[y];}
int f(int x,int y) {if(x>y) y+=ans/ps;y-=x-1;return x+(y-1)*ps;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),ds[++ds[0]]=a[i];
	sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=n;++i)
		++cnt[lower_bound(ds+1,ds+ds[0]+1,a[i])-ds];
	for(int i=1;i<=ds[0];++i) ord[i]=i;sort(ord+1,ord+ds[0]+1,cmp);
	for(int i=1,t=1,nw=0;i*i<=n;++i)
	{
		nw+=ds[0]-t+1;while(t<=ds[0] && cnt[ord[t]]<=i) ++t;
		if(nw>=i*i && nw/i*i>ans) ans=nw/i*i,ps=i;
	}printf("%d\n%d %d\n",ans,ps,ans/ps);
	for(int i=ds[0];i;--i) for(int j=1;j<=min(cnt[ord[i]],ps);++j)
		st[++st[0]]=ds[ord[i]];
	for(int i=1;i<=ps;++i,puts("")) for(int j=1;j<=ans/ps;++j)
		printf("%d ",st[f(i,j)]);return 0;
}