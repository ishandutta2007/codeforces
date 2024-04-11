#include <bits/stdc++.h>
using namespace std;
#define N 5005
#define M 55
#define C 1<<20
int n,m,m1,m2,tp,a[N],id[M],lg[C],stt[M][M];bool tg[C],dp1[C],dp2[C];
char a1[N],rv[M],ans[M];struct Node {int l,r,w;}b[M],z[C];
int main()
{
	scanf("%d %d %d %s",&n,&m1,&m2,a1+1);
	tg[0]=dp2[0]=1;z[0].l=1e9;for(int i=0;i<26;++i) id[i]=-1;
	for(int i=1,t;i<=n;++i)
	{
		t=a1[i]-'a';if(id[t]==-1) id[t]=m++,b[id[t]]=(Node) {i,i,0};
		b[id[t]].r=i;++b[id[t]].w;a[i]=id[t];rv[id[t]]=a1[i];
	}for(int i=2;i<1<<m;++i) lg[i]=lg[i/2]+1;
	for(int i=0;i<m;++i) for(int j=0;j<m;++j) for(int k=0;k<m;++k)
		if(b[k].l>=b[i].l && b[k].l<=b[j].r) stt[i][j]|=1<<k;
	for(int i=1,t;i<1<<m;++i)
	{
		z[i]=z[i&i-1];t=lg[i&-i];z[i].w+=b[t].w;
		z[i].l=min(z[i].l,b[t].l);z[i].r=max(z[i].r,b[t].r);
		if(z[i].w*m2>=(z[i].r-z[i].l+1)*m1) tg[i]=1;
	}
	for(int i=1,t;i<1<<m;++i)
	{
		if(tg[i]) for(int j=0;j<m;++j) if(i>>j&1) dp1[i]|=dp2[i^(1<<j)];
		for(int j=0;j<m;++j) t=i&stt[a[z[i].l]][j],dp2[i]|=dp1[t]&dp2[i^t];
	}for(int i=0;i<m;++i) if(dp2[(1<<i)^(1<<m)-1]) ans[tp++]=rv[i];
	sort(ans,ans+tp);printf("%d ",tp);
	for(int i=0;i<tp;++i) printf("%c ",ans[i]);return 0;
}