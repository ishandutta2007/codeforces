#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500000;
const int inf=1000000000000000;
struct node
{
	int l,r;
	pair<int,int> s;
};
struct SegmentTree
{
	node t[maxn*4+5];
	void build(int p,int l,int r)
	{
		t[p].l=l;
		t[p].r=r;
		t[p].s=make_pair(inf,l);
		if(l==r) return;
		int mid=(l+r)/2;
		build(p*2,l,mid);
		build(p*2+1,mid+1,r);
		return;
	}
	void change(int p,int x,int v)
	{
		if(t[p].l==x&&t[p].r==x) 
		{
			t[p].s.first=v;
			return;
		}
		int mid=(t[p].l+t[p].r)/2;
		if(x<=mid) change(p*2,x,v);
		if(x>mid) change(p*2+1,x,v);
		t[p].s=min(t[p*2].s,t[p*2+1].s);
		return;
	}
	pair<int,int> query(int p,int l,int r)
	{
		if(l<=t[p].l&&t[p].r<=r) return t[p].s;
		int mid=(t[p].l+t[p].r)/2;
		pair<int,int> res=make_pair(inf,inf);
		if(l<=mid) res=min(res,query(p*2,l,r));
		if(r>mid) res=min(res,query(p*2+1,l,r));
		return res;
	}
}T;
int n,q;
vector<int> que[maxn+5],id[maxn+5];
int pos[maxn+5],a[maxn+5],ans[maxn+5];
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	scanf("%lld",&q);
	int l,r;
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&l,&r);
		que[r].push_back(l);
		id[r].push_back(i);
	}
	T.build(1,1,n);
	for(int i=1;i<=n;i++) 
	{
		if(pos[a[i]])
		{
			T.change(1,pos[a[i]],inf);
			T.change(1,i,pos[a[i]]);
			pos[a[i]]=i;
		}
		else pos[a[i]]=i,T.change(1,i,-inf);
		for(int j=0;j<que[i].size();j++)
		{
			if(T.query(1,que[i][j],i).first<que[i][j]) ans[id[i][j]]=a[T.query(1,que[i][j],i).second];
			else ans[id[i][j]]=0;
		}
	}
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}