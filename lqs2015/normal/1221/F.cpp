#include<bits/stdc++.h>
using namespace std;
int n,x[555555],y[555555],c[555555],arr[2222222],cnt,ansl,ansr;
pair<long long,int> tree[4444444],res;
long long lazy[4444444],ans;
map<int,int> mp;
vector<int> xx[2222222];
void pushup(int node)
{
	tree[node]=max(tree[(node<<1)|1],tree[node<<1]);
}
void push(int node,long long x)
{
	tree[node].first+=x;lazy[node]+=x;
}
void pushdown(int node)
{
	if (lazy[node])
	{
		push(node<<1,lazy[node]);
		push((node<<1)|1,lazy[node]);
		lazy[node]=0;
	}
}
void build(int l,int r,int node)
{
	if (l==r)
	{
		tree[node].first=-1ll*arr[l];
		tree[node].second=l;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	pushup(node);
}
void update(int beg,int en,int l,int r,int node,int x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		push(node,x);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(node);
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
	pushup(node);
}
pair<long long,int> query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return make_pair(-1e18,-1e18);
	if (l>=beg && r<=en) return tree[node];
	pushdown(node);
	int mid=(l+r)>>1;
	return max(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&c[i]);
		if (x[i]>y[i]) swap(x[i],y[i]);
		arr[++cnt]=x[i];arr[++cnt]=y[i];
	}
	sort(arr+1,arr+cnt+1);
	cnt=unique(arr+1,arr+cnt+1)-arr-1;
	for (int i=1;i<=cnt;i++) mp[arr[i]]=i;
	for (int i=1;i<=n;i++)
	{
		x[i]=mp[x[i]];
		y[i]=mp[y[i]];
		xx[x[i]].push_back(i);
	}
	build(1,cnt,1);
	for (int i=1;i<=n;i++)
	{
		update(y[i],cnt,1,cnt,1,c[i]);
	}
	ans=-1e18;
	for (int i=1;i<=cnt;i++)
	{
		res=query(i,cnt,1,cnt,1);
		res.first+=arr[i];
		if (res.first>ans)
		{
			ans=res.first;
			ansl=arr[i];ansr=arr[res.second];
		}
		for (int j=0;j<xx[i].size();j++)
		{
			int id=xx[i][j];
			update(y[id],cnt,1,cnt,1,-c[id]);
		}
	}
	if (ans<0)
	{
		printf("0\n");
		printf("%d %d %d %d\n",arr[cnt]+1,arr[cnt]+1,arr[cnt]+1,arr[cnt]+1);
		return 0;
	}
	printf("%lld\n",ans);
	printf("%d %d %d %d\n",ansl,ansl,ansr,ansr);
	return 0;
}