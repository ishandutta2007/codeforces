#include <bits/stdc++.h>
using namespace std;
#define N 600005
mt19937 rand1(time(0));
int n,m,a[N],a1[N],w[N],ds[N],bt[N],ans[N];struct Node {int l,r,vl,id;}b[N];
int qId(int x) {return lower_bound(ds+1,ds+ds[0]+1,x)-ds;}
void clear() {for(int i=1;i<=n;++i) bt[i]=0;}
void upd(int x,int vl) {for(;x<=n;x+=x&-x) bt[x]+=vl;}
int qSm(int x) {int res=0;for(;x;x-=x&-x) res+=bt[x];return res;}
void slv()
{
	clear();for(int i=1;i<=ds[0];++i) w[i]=rand1()&1;
	for(int i=1;i<=n;++i) a1[i]=a[i],upd(i,w[a[i]]);
	for(int i=1;i<=m;++i) if(b[i].id)
	{if(!ans[b[i].id]) ans[b[i].id]=(qSm(b[i].r)-qSm(b[i].l-1))%b[i].vl;}
	else upd(b[i].l,-w[a1[b[i].l]]),a1[b[i].l]=b[i].vl,upd(b[i].l,w[b[i].vl]);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),ds[++ds[0]]=a[i];
	for(int i=1,op;i<=m;++i)
	{
		scanf("%d %d",&op,&b[i].l);
		if(op==2) scanf("%d",&b[i].r),b[i].id=++ans[0];
		scanf("%d",&b[i].vl);if(op==1) ds[++ds[0]]=b[i].vl;
	}sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=n;++i) a[i]=qId(a[i]);
	for(int i=1;i<=m;++i) if(!b[i].id) b[i].vl=qId(b[i].vl);
	for(int i=1;i<=30;++i) slv();
	for(int i=1;i<=ans[0];++i) if(ans[i])
		printf("NO\n");else printf("YES\n");return 0;
}