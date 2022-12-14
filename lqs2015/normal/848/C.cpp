#include<bits/stdc++.h>
using namespace std;
long long n,m,a[111111],sz,rt[888888],tp,x,y;
set<long long> s[111111];
set<long long>::iterator it,itt,iter;
struct node
{
	long long sum;
	int l,r;
}tree[13888888];
long long upd(long long beg,long long en,long long l,long long r,long long node,long long tx)
{
	if (!node) node=++sz;
	if (l>en || r<beg) return node;
	if (l>=beg && r<=en) 
	{
		tree[node].sum+=tx;
		return node;
	}
	long long mid=(l+r)>>1;
	tree[node].l=upd(beg,en,l,mid,tree[node].l,tx);
	tree[node].r=upd(beg,en,mid+1,r,tree[node].r,tx);
	return node;
}
void update(long long beg,long long en,long long xl,long long xr,long long l,long long r,long long node,long long tx)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		rt[node]=upd(xl,xr,1,n,rt[node],tx);
		return;
	}
	long long mid=(l+r)>>1;
	update(beg,en,xl,xr,l,mid,node<<1,tx);
	update(beg,en,xl,xr,mid+1,r,(node<<1)|1,tx);
}
long long qry(long long x,long long l,long long r,long long node)
{
	if (!node) return 0;
	if (l==r) return tree[node].sum;
	long long mid=(l+r)>>1;
	if (x>mid) return tree[node].sum+qry(x,mid+1,r,tree[node].r);
	return tree[node].sum+qry(x,l,mid,tree[node].l);
}
long long query(long long x,long long y,long long l,long long r,long long node)
{
	if (l==r) return qry(y,1,n,rt[node]);
	long long mid=(l+r)>>1;
	if (x>mid) return qry(y,1,n,rt[node])+query(x,y,mid+1,r,(node<<1)|1);
	return qry(y,1,n,rt[node])+query(x,y,l,mid,node<<1);
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[a[i]].insert(i); 
	}
	for (long long i=1;i<=n;i++)
	{
		if (s[i].empty()) continue;
		for (it=s[i].begin(),itt=it,itt++;itt!=s[i].end();it++,itt++)
		{
			update(1,*it,*itt,n,1,n,1,*itt-*it);
		}
	}
	while(m--)
	{
		scanf("%lld%lld%lld",&tp,&x,&y);
		if (tp==1)
		{
			it=s[a[x]].lower_bound(x);
			if (it!=s[a[x]].begin())
			{
				itt=it;
				itt--;
				it++;
				update(1,*itt,x,n,1,n,1,-x+*itt);
				if (it!=s[a[x]].end())
				{
					update(1,x,*it,n,1,n,1,-*it+x);
					update(1,*itt,*it,n,1,n,1,*it-*itt);
				}
			} 
			else
			{
				it++;
				if (it!=s[a[x]].end())
				{
					update(1,x,*it,n,1,n,1,-*it+x);
				}
			} 
			s[a[x]].erase(s[a[x]].find(x));
			it=s[y].lower_bound(x);
			if (!s[y].empty())
			{
				if (it!=s[y].end() && it!=s[y].begin())
				{
					itt=it;
					itt--;
					update(1,*itt,*it,n,1,n,1,*itt-*it);
					update(1,*itt,x,n,1,n,1,x-*itt);
					update(1,x,*it,n,1,n,1,*it-x);
				} 
				else if (it!=s[y].end())
				{
					update(1,x,*it,n,1,n,1,*it-x);
				}
				else if (it!=s[y].begin())
				{
					it--;
					update(1,*it,x,n,1,n,1,x-*it);
				}
			}
			s[y].insert(x); 
			a[x]=y;
		}
		else
		{
			printf("%lld\n",query(x,y,1,n,1));
		}
	}
	return 0;
}