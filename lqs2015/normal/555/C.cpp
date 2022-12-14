#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,q,x[222222],y[222222],col[222222],rw[222222],sumcol,sumrw,cc,cur,curr;
int treecol[888888],treerw[888888],sz;
map<int,int> mp;
char c[222222];
void update(int beg,int en,int l,int r,int node,int x,int tree[])
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		tree[node]=max(tree[node],x);
		return;
	}
	int mid=(l+r)/2;
	update(beg,en,l,mid,node*2,x,tree);
	update(beg,en,mid+1,r,node*2+1,x,tree);
}
int query(int x,int tree[])
{
	int pos=sz-1+x,res=0;
	while(pos>=1)
	{
		res=max(res,tree[pos]);
		pos/=2;
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d %d %c",&y[i],&x[i],&c[i]);
		if (c[i]=='U') col[++sumcol]=y[i];
		else rw[++sumrw]=x[i];
	}
	sort(col+1,col+sumcol+1);
	sort(rw+1,rw+sumrw+1);
	sz=1<<18;
	for (int i=1;i<=q;i++)
	{
		if (mp.find(x[i])!=mp.end())
		{
			printf("0\n");
			continue;
		}
		mp[x[i]]=1;
		if (c[i]=='U')
		{
			cc=lower_bound(col+1,col+sumcol+1,y[i])-col;
			cur=query(cc,treecol);
			printf("%d\n",x[i]-rw[cur]);
			curr=lower_bound(rw+1,rw+sumrw+1,x[i]+1)-rw;
			if (curr>sumrw || rw[curr]>x[i]) curr--;
			update(cur+1,curr,1,sz,1,cc,treerw);
		}
		else 
		{
			cc=lower_bound(rw+1,rw+sumrw+1,x[i])-rw;
			cur=query(cc,treerw);
			printf("%d\n",y[i]-col[cur]);
			curr=lower_bound(col+1,col+sumcol+1,y[i]+1)-col;
			if (curr>sumcol || col[curr]>y[i]) curr--;
			update(cur+1,curr,1,sz,1,cc,treecol);
		}
	}
	return 0;
}