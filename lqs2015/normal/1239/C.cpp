#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,p,t[111111],r;
pair<long long,int> tree[444444];
pair<int,int> a[111111];
long long ans[111111],cur;
set<int> s;
set<pair<int,int> > ss;
set<pair<int,int> >::iterator it,itt;
void build(int l,int r,int node)
{
	if (l==r)
	{
		tree[node]=make_pair((long long)t[l],l);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
}
pair<long long,int> query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return make_pair(1e18,1e9);
	if (l>=beg && r<=en) return tree[node];
	int mid=(l+r)>>1;
	return min(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
}
void upd(int x,int l,int r,int node)
{
	if (l==r) 
	{
		tree[node]=make_pair(1e18,1e9);
		return;
	}
	int mid=(l+r)>>1;
	if (x>mid) upd(x,mid+1,r,(node<<1)|1);
	else upd(x,l,mid,node<<1);
	tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
}
int main()
{
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
	}
	build(1,n,1);
	for (int i=1;i<=n;i++)
	{
		ss.insert(make_pair(t[i],i));
	}
	while(1)
	{
		if (s.empty() && ss.empty()) break;
		if (!s.empty())
		{
			int id=*s.begin();
			s.erase(s.begin());
			cur+=p;ans[id]=cur;
			upd(id,1,n,1);
			while(1)
			{
				pair<long long,int> res=query(1,id-1,1,n,1);
				if (res.first<=cur) 
				{
					id=res.second;
					cur+=p;ans[id]=cur;
					upd(id,1,n,1);
					if (s.find(id)!=s.end()) s.erase(s.find(id));
					if (ss.find(make_pair(t[id],id))!=ss.end()) ss.erase(ss.find(make_pair(t[id],id)));
				}
				else break;
			}
		}
		else
		{
			int id=ss.begin()->second;
			ss.erase(ss.begin());
			cur=1ll*t[id]+p;ans[id]=cur;
			upd(id,1,n,1);
			while(1)
			{
				pair<long long,int> res=query(1,id-1,1,n,1);
				if (res.first<=cur) 
				{
					id=res.second;
					cur+=p;ans[id]=cur;
					upd(id,1,n,1);
					if (s.find(id)!=s.end()) s.erase(s.find(id));
					if (ss.find(make_pair(t[id],id))!=ss.end()) ss.erase(ss.find(make_pair(t[id],id)));
				}
				else break;
			}
		}
		for (it=ss.begin();it!=ss.end();it=itt)
		{
			itt=it;itt++;
			if ((it->first)<=cur) 
			{
				s.insert(it->second);
				ss.erase(it);
			}
			else break;
		}
	}
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return Accepted;
}