#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define M 25
#define pb push_back
int n,m,vl[M],ps[M],a[N],L[N],ans[N];vector<int> vc[N];
void ins(int w,int x)
{
	for(int i=19;i>=0;--i) if(w>>i&1)
	{
		if(!vl[i]) {vl[i]=w;ps[i]=x;break;}
		if(x>ps[i]) swap(x,ps[i]),swap(w,vl[i]);w^=vl[i];
	}
}
int qXor(int x)
{
	int res=0;
	for(int i=19;i>=0;--i) if(ps[i]>=x && (res^vl[i])>res)
		res^=vl[i];return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);scanf("%d",&m);
	for(int i=1,r;i<=m;++i) scanf("%d %d",&L[i],&r),vc[r].pb(i);
	for(int i=1,t;i<=n;++i)
	{
		ins(a[i],i);
		for(int j=0;j<vc[i].size();++j) t=vc[i][j],ans[t]=qXor(L[t]);
	}for(int i=1;i<=m;++i) printf("%d\n",ans[i]);return 0;
}