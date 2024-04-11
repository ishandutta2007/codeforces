#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int lazy[801000],l[801000],r[801000],sum[801000],x[201000],y[201000];
struct xxx{int l,r,id;}q[201000];int ans[201000];
bool cmp(xxx a,xxx b){return a.l<b.l;}
void pushdown(int x)
{
	if(lazy[x]==-1)return;lazy[x<<1]=lazy[x];lazy[x<<1|1]=lazy[x];
	sum[x<<1]=lazy[x]*(r[x<<1]-l[x<<1]+1);sum[x<<1|1]=lazy[x]*(r[x<<1|1]-l[x<<1|1]+1);
	lazy[x]=0;
}
void build(int x,int L,int R)
{
	l[x]=L;r[x]=R;lazy[x]=-1;if(L==R)return;
	build(x<<1,L,L+R>>1);build(x<<1|1,(L+R>>1)+1,R);
}
void modify(int x,int L,int R,int k)
{//cout<<x<<" "<<l[x]<<" "<<r[x]<<" "<<L<<" "<<R<<endl;
	if(l[x]==L&&r[x]==R){lazy[x]=k;sum[x]=lazy[x]*(r[x]-l[x]+1);return;}
	pushdown(x);int mid=l[x]+r[x]>>1;
	if(R<=mid)modify(x<<1,L,R,k);
	else if(L>mid)modify(x<<1|1,L,R,k);
	else modify(x<<1,L,mid,k),modify(x<<1|1,mid+1,R,k);
	sum[x]=sum[x<<1]+sum[x<<1|1];
}
int query(int x,int L,int R)
{//cout<<x<<" "<<l[x]<<" "<<r[x]<<" "<<L<<" "<<R<<endl;
	if(l[x]==L&&r[x]==R){return sum[x];}
	pushdown(x);int mid=l[x]+r[x]>>1;
	if(R<=mid)return query(x<<1,L,R);
	else if(L>mid)return query(x<<1|1,L,R);
	else return query(x<<1,L,mid)+query(x<<1|1,mid+1,R);
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);build(1,1,n);
	int m;scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1,cmp);int j=m;//for(int i=1;i<=m;i++)cout<<q[i].l<<' '<<q[i].r<<endl;
	for(int i=n;i>=1;i--)
	{
		int u=upper_bound(x+1,x+n+1,x[i]+y[i])-x-1,sp;if(u>i)modify(1,i,u-1,0);
		if(u!=i&&u<=n)sp=query(1,u,u);else sp=1<<30;if(u+1<=n)modify(1,u,u,min(sp,x[u+1]-(x[i]+y[i])));//cout<<i<<" "<<u<<" "<<sp<<endl;
	//	P(1);for(int o=1;o<=n;o++)cout<<query(1,o,o)<<" ";cout<<endl;
		while(j>0&&q[j].l==i){ans[q[j].id]=query(1,q[j].l,q[j].r-1);j--;}
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
 } 
 //iii~i+1 lazy-10