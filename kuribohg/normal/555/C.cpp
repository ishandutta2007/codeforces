#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5000010;
struct Segment_Tree
{
	int root,tot;
	int lch[MAXN],rch[MAXN];
	int lazy[MAXN],Max[MAXN];
	void PushDown(int x)
	{
		if(!lch[x]) lch[x]=++tot;
		if(!rch[x]) rch[x]=++tot;
		lazy[lch[x]]=max(lazy[lch[x]],lazy[x]);
		Max[lch[x]]=max(Max[lch[x]],lazy[x]);
		lazy[rch[x]]=max(lazy[rch[x]],lazy[x]);
		Max[rch[x]]=max(Max[rch[x]],lazy[x]);
		lazy[x]=0;
	}
	void Change(int &x,int l,int r,int ql,int qr,int tar)
	{
		if(ql>qr) return;
		if(!x) x=++tot;
		if(l==ql&&r==qr)
		{
			lazy[x]=max(lazy[x],tar);
			Max[x]=max(Max[x],tar);
			return;
		}
		PushDown(x);
		int mid=(l+r)>>1;
		if(qr<=mid) Change(lch[x],l,mid,ql,qr,tar);
		else if(ql>mid) Change(rch[x],mid+1,r,ql,qr,tar);
		else Change(lch[x],l,mid,ql,mid,tar),Change(rch[x],mid+1,r,mid+1,qr,tar);
		Max[x]=max(Max[lch[x]],Max[rch[x]]);
	}
	int Query(int x,int l,int r,int pos)
	{
		if(!x) return 0;
		if(l==r) return Max[x];
		PushDown(x);
		int mid=(l+r)>>1;
		if(pos<=mid) return Query(lch[x],l,mid,pos);
		else return Query(rch[x],mid+1,r,pos);
	}
}R,C;
int n,Q,x,y;
char op[10];
int main()
{
	scanf("%d%d",&n,&Q);
	while(Q--)
	{
		scanf("%d%d%s",&x,&y,op);
		if(op[0]=='U')
		{
			int limit=R.Query(R.root,1,n,x);
			printf("%d\n",y-limit);
			C.Change(C.root,1,n,limit+1,y,x);
			R.Change(R.root,1,n,x,x,y);
		}
		else
		{
			int limit=C.Query(C.root,1,n,y);
			printf("%d\n",x-limit);
			R.Change(R.root,1,n,limit+1,x,y);
			C.Change(C.root,1,n,y,y,x);
		}
	}
	return 0;
}