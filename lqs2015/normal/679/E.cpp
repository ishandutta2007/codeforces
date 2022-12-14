#include<iostream>
#include<cstdio>
#include<set> 
#include<vector>
using namespace std;
long long tree[444444],cr,lazy[444444],tag[444444],pw[15],a[444444],n,q,t[111111],pos,sz,l,r,x,tp;
bool f;
multiset<pair<long long,long long> > s;
multiset<pair<long long,long long> >::iterator it;
vector<pair<long long,long long> > del;
void build(long long l,long long r,long long node)
{
	if (l==r)
	{
		if (l<=n) tree[node]=t[l];
		else tree[node]=1e18;
		return;
	}
	long long mid=(l+r)/2;
	build(l,mid,node*2);
	build(mid+1,r,node*2+1);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}
void pushdown(long long node)
{
	if (tag[node])
	{
		tag[node*2+1]=tag[node*2]=1;
		tree[node*2]=tree[node*2+1]=1e18;
		tag[node]=0;
	}
	if (lazy[node])
	{
		lazy[node*2+1]+=lazy[node];lazy[node*2]+=lazy[node];
		tree[node*2+1]+=lazy[node];tree[node*2]+=lazy[node];
		lazy[node]=0;
	}
}
void update(long long beg,long long en,long long l,long long r,long long node,long long x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		tree[node]+=x;
		lazy[node]+=x;
		return;
	}
	long long mid=(l+r)/2;
	pushdown(node);
	update(beg,en,l,mid,node*2,x);
	update(beg,en,mid+1,r,node*2+1,x);
	tree[node]=min(tree[node*2+1],tree[node*2]);
}
void push(long long l,long long r,long long node)
{
	if (tree[node]>0) return;
	if (l==r)
	{
		if (!tree[node]) f=1;
		else
		{
			long long x=pw[a[l]]-tree[node];
			while(pw[a[l]]<x) a[l]++;
			if (pw[a[l]]==x) f=1;
			tree[node]=pw[a[l]]-x;  
		}
		return;
	}
	long long mid=(l+r)/2;
	pushdown(node);
	push(l,mid,node*2);
	push(mid+1,r,node*2+1);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}
void update2(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		tree[node]=1e18;
		tag[node]=1;
		return;
	}
	long long mid=(l+r)/2;
	pushdown(node);
	update2(beg,en,l,mid,node*2);
	update2(beg,en,mid+1,r,node*2+1);
	tree[node]=min(tree[node*2+1],tree[node*2]);
}
void updt(long long x,long long l,long long r,long long node,long long y)
{
	if (l==r)
	{
		tree[node]=y;
		return;
	}
	pushdown(node);
	long long mid=(l+r)/2;
	if (x>mid) updt(x,mid+1,r,node*2+1,y);
	else updt(x,l,mid,node*2,y);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}
long long query(long long x,long long l,long long r,long long node)
{
	if (l==r) 
	{
		return pw[a[l]]-tree[node];
	}
	long long mid=(l+r)/2;
	pushdown(node);
	if (x>mid) return query(x,mid+1,r,node*2+1);
	return query(x,l,mid,node*2);
}
long long query(long long x)
{
	it=s.lower_bound(make_pair(x,0));
	if (it==s.end() || it->first>x)
	{
		if (it==s.begin()) return query(x,1,sz,1);
		it--;
	}
	if (it->second>=x) return query(it->second,1,sz,1);
	return query(x,1,sz,1);
}
void split(long long x)
{
	it=s.lower_bound(make_pair(x,0));
	if (it==s.end() || it->first>x)
	{
		if (it==s.begin()) return;
		it--;
	}
	if (it->second>=x)
	{
		s.insert(make_pair(it->first,x));
		if (it->second>x) s.insert(make_pair(x+1,it->second));
		s.erase(it);   
	}
}
void upd(long long x)
{
	if (!x) return;
	if (query(x,1,sz,1)<=-1e16)
	{
		cr=query(x);split(x);a[x]=0;
		while(pw[a[x]]<cr) a[x]++;
		updt(x,1,sz,1,pw[a[x]]-cr);
	}
}
long long add(long long l,long long r)
{
	del.clear();
	for (it=s.lower_bound(make_pair(l,0));it!=s.end();it++)
	{
		if (it->first<l) continue;
		if (it->second>r) break;
		del.push_back(make_pair(it->first,it->second));
	}
	for (long long i=0;i<del.size();i++) s.erase(s.find(del[i])); 
	s.insert(make_pair(l,r)); 
}
int main()
{
	pw[0]=1ll;
	for (long long i=1;i<=11;i++) pw[i]=pw[i-1]*42ll;
	scanf("%I64d%I64d",&n,&q);
	sz=1;
	while(sz<n) sz*=2;
	for (long long i=1;i<=n;i++) scanf("%I64d",&t[i]);
	for (long long i=1;i<=n;i++)
	{
		while(pw[a[i]]<t[i]) a[i]++;
		t[i]=pw[a[i]]-t[i];
	}
	build(1,sz,1);
	while(q--)
	{
		scanf("%I64d",&tp);
		if (tp==1)
		{
			scanf("%I64d",&x);
			printf("%I64d\n",query(x));
		}
		else if (tp==2)
		{
			scanf("%I64d%I64d%I64d",&l,&r,&x);
			upd(l-1);
			a[r]=0;
			while(pw[a[r]]<x) a[r]++;
			updt(r,1,sz,1,pw[a[r]]-x);
			update2(l,r-1,1,sz,1);
			split(r);
			add(l,r);
		}
		else
		{
			scanf("%I64d%I64d%I64d",&l,&r,&x);
			upd(l-1);
			upd(r);
			while(1)
			{
				f=0;
				update(l,r,1,sz,1,-x);
				push(1,sz,1);
				if (!f) break;
			}
		}
	}
	return 0;
}