#include<bits/stdc++.h>
using namespace std;

const int maxn=500010;
int a[maxn],pre[maxn];
int pos[maxn];
int n,m;

struct Ques
{
	int l,r;
	int id;
	int ans;
}	ques[maxn];
int seg[maxn<<2];
void build(int t,int l,int r)
{
	seg[t]=n+1;
	if (l==r)	return;
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
}
bool cmp(const Ques &a,const Ques &b)
{
	return a.r<b.r;
}
bool cmp_id(const Ques &a,const Ques &b)
{
	return a.id<b.id;
}
void change(int t,int l,int r,int pos,int x)
{
	if (l==r)
	{
		seg[t]=x;
		return;
	}
	int mid=(l+r)>>1;
	if (pos<=mid)	change(t<<1,l,mid,pos,x);else change(t<<1|1,mid+1,r,pos,x);
	seg[t]=min(seg[t<<1],seg[t<<1|1]);
}
int query(int t,int l,int r,int ql,int qr,int x)
{
	if (seg[t]>x)	return 0;
	if (l==r)	return l;
	int mid=(l+r)>>1;
	if (ql>mid)	return query(t<<1|1,mid+1,r,ql,qr,x);
	if (seg[t<<1|1]<=x)	return query(t<<1|1,mid+1,r,mid+1,r,x);else return query(t<<1,l,mid,ql,mid,x);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pre[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&ques[i].l,&ques[i].r);
		ques[i].id=i;
	}
	build(1,1,n);
	sort(ques+1,ques+m+1,cmp);
	int now=1;
	for (int i=1;i<=n;i++)
	{
		change(1,1,n,i,pre[i]);
		if (pre[i]!=0)	change(1,1,n,pre[i],n+1);
		while (now<=m && ques[now].r==i)
		{
			ques[now].ans=a[query(1,1,n,ques[now].l,n,ques[now].l-1)];
			now++;
		}
	}
	sort(ques+1,ques+m+1,cmp_id);
	for (int i=1;i<=m;i++)
		printf("%d\n",ques[i].ans);
	return 0;
}