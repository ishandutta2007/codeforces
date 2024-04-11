#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define maxn 200010
struct Ques
{
	int op;
	ll ql,qr;
	int l,r;
}	que[maxn];
ll num[maxn<<1];int cnt;
int n;

struct Seg
{
	int num,tag;//1=full 0=empty -1=mix
}	seg[maxn<<2];
void tag_rev(int t)
{
	if (seg[t].num==-1)	seg[t].tag^=1;else	seg[t].num^=1;
}
void down(int t)
{
	if (seg[t].num==-1 && !seg[t].tag)	return;
	if (seg[t].num==-1 && seg[t].tag)
	{
		tag_rev(t<<1);
		tag_rev(t<<1|1);
		seg[t].tag=0;
	}	else
	{
		if (seg[t].num==1)
		{
			seg[t<<1].num=1;
			seg[t<<1].tag=0;
			seg[t<<1|1].num=1;
			seg[t<<1|1].tag=0;
		}	else
		if (seg[t].num==0)
		{
			seg[t<<1].num=0;
			seg[t<<1].tag=0;
			seg[t<<1|1].num=0;
			seg[t<<1|1].tag=0;
		}
	}
	return;
}
void maintain(int t)
{
	if (seg[t<<1].num==-1 || seg[t<<1|1].num==-1)	seg[t].num=-1;
	if (seg[t<<1].num==seg[t<<1|1].num)	seg[t].num=seg[t<<1].num;else seg[t].num=-1;
}
void insert(int t,int l,int r,int ql,int qr)
{
	if (l>=ql && r<=qr)
	{
		seg[t].num=1,seg[t].tag=0;
		return;
	}
	down(t);
	int mid=(l+r)>>1;
	if (qr<=mid)	insert(t<<1,l,mid,ql,qr);else
	if (ql>mid)		insert(t<<1|1,mid+1,r,ql,qr);else
	{insert(t<<1,l,mid,ql,mid);insert(t<<1|1,mid+1,r,mid+1,qr);}
	maintain(t);
}
void del(int t,int l,int r,int ql,int qr)
{
	if (l>=ql && r<=qr)
	{
		seg[t].num=0,seg[t].tag=0;
		return;
	}
	down(t);
	int mid=(l+r)>>1;
	if (qr<=mid)	del(t<<1,l,mid,ql,qr);else
	if (ql>mid)		del(t<<1|1,mid+1,r,ql,qr);else
	{del(t<<1,l,mid,ql,mid);del(t<<1|1,mid+1,r,mid+1,qr);}
	maintain(t);
}
void rev(int t,int l,int r,int ql,int qr)
{
	if (l>=ql && r<=qr)
	{
		tag_rev(t);
		return;
	}
	down(t);
	int mid=(l+r)>>1;
	if (qr<=mid)	rev(t<<1,l,mid,ql,qr);else
	if (ql>mid)		rev(t<<1|1,mid+1,r,ql,qr);else
	{rev(t<<1,l,mid,ql,mid);rev(t<<1|1,mid+1,r,mid+1,qr);}
	maintain(t);
}
int query(int t,int l,int r)
{
	if (l==r)	return l;
	down(t);
	int mid=(l+r)>>1;
	if (seg[t<<1].num!=1)	return query(t<<1,l,mid);else return query(t<<1|1,mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%I64d%I64d",&que[i].op,&que[i].ql,&que[i].qr);
		que[i].qr++;
		num[++cnt]=que[i].ql;
		num[++cnt]=que[i].qr;
	}
	num[++cnt]=1;
	sort(num+1,num+cnt+1);
	cnt=unique(num+1,num+cnt+1)-(num+1);
	for (int i=1;i<=n;i++)
	{
		que[i].l=lower_bound(num+1,num+cnt+1,que[i].ql)-num;
		que[i].r=lower_bound(num+1,num+cnt+1,que[i].qr)-num;
	}
	for (int i=1;i<=n;i++)
	{
		if (que[i].op==1)	insert(1,1,cnt,que[i].l,que[i].r-1);else
		if (que[i].op==2)	del(1,1,cnt,que[i].l,que[i].r-1);else
		rev(1,1,cnt,que[i].l,que[i].r-1);
		int ans=query(1,1,cnt);
		printf("%I64d\n",num[ans]);
	}
	return 0;
}