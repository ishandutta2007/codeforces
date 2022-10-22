#include<bits/stdc++.h>
#define N 300010
#define mid ((l+r)>>1)
#define ls a[t].l
#define rs a[t].r
using namespace std;int x,y,cnt,rt[N];
struct dt{int c,l,r,f;}a[N*30],e[N];inline void bil(int &t,int k){a[t=++cnt]=a[k];}
inline void upd(int t,int l,int r)
{
	while (l<r) {int &q=(x<=mid?ls:rs);bil(q,q),a[q].f=t,t=q;x<=mid?r=mid:l=mid+1;}
	a[t].c=max(a[t].c,y);t=a[t].f;while (t) a[t].c=min(a[ls].c,a[rs].c),t=a[t].f;
}
int qry(int t,int l,int r)
{
	if (x<=l && r<=y) return a[t].c;
	return min(x<=mid?qry(ls,l,mid):2e9,y>mid?qry(rs,mid+1,r):2e9);
}
int main()
{
	int n,m,k,i,c,d;scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=k;i++) scanf("%d%d%d",&e[i].l,&e[i].r,&e[i].c);
	sort(e+1,e+k+1,[](const dt&x,const dt&y){return x.r<y.r;});
	for (i=1;i<=k;i++) bil(rt[i],rt[i-1]),x=e[i].c,y=e[i].l,upd(rt[i],1,n);
	while (m--)
	{
		scanf("%d%d%d%d",&x,&y,&c,&d);int l=0,r=k+1;
		while (l<r-1) e[mid].r<=d?l=mid:r=mid;
		puts(qry(rt[l],1,n)>=c?"yes":"no");cout.flush();
	}
}