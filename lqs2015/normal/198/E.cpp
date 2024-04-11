#include<bits/stdc++.h>
using namespace std;
int x,y,p[333333],r[333333],n,m[333333],X,Y,brr[333333],cnta,cntb,ans;
int tree[2222222],pos[333333];
long long d[333333],arr[333333];
map<long long,int> mp1;
map<int,int> mp2;
vector<pair<int,int> > v[333333];
queue<int> q;
void pushup(int node)
{
	tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
}
void build(int l,int r,int node)
{
	if (l==r)
	{
		if (v[l].empty()) tree[node]=1e9;
		else tree[node]=v[l][0].first;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	pushup(node);
}
void update(int beg,int en,int l,int r,int node,int w)
{
	if (l>en || r<beg) return;
	if (tree[node]>w) return;
	if (l==r)
	{
		while(pos[l]<v[l].size() && v[l][pos[l]].first<=w)	
		{
			q.push(v[l][pos[l]].second);
			pos[l]++;	
		}
		if (pos[l]==(int)v[l].size()) tree[node]=1e9;
		else tree[node]=v[l][pos[l]].first;
		return;
	}
	int mid=(l+r)>>1;
	update(beg,en,l,mid,node<<1,w);
	update(beg,en,mid+1,r,(node<<1)|1,w);
	pushup(node);
}
int main()
{
	scanf("%d%d%d%d%d",&x,&y,&p[0],&r[0],&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d%d",&X,&Y,&m[i],&p[i],&r[i]);
		d[i]=1ll*(X-x)*(X-x)+1ll*(Y-y)*(Y-y);arr[i]=d[i];brr[i]=m[i];
	}
	sort(arr+1,arr+n+1);
	cnta=unique(arr+1,arr+n+1)-arr-1;
	for (int i=1;i<=cnta;i++) mp1[arr[i]]=i;
	sort(brr+1,brr+n+1);
	cntb=unique(brr+1,brr+n+1)-brr-1;
	for (int i=1;i<=cntb;i++) mp2[brr[i]]=i;
	for (int i=0;i<=n;i++)
	{
		d[i]=mp1[d[i]];m[i]=mp2[m[i]];
		p[i]=lower_bound(brr+1,brr+cntb+1,p[i]+1)-brr-1;
		r[i]=lower_bound(arr+1,arr+cnta+1,1ll*r[i]*r[i]+1)-arr-1;
	}
	for (int i=1;i<=n;i++)
	{
		v[d[i]].push_back(make_pair(m[i],i));
	}
	for (int i=1;i<=cnta;i++) sort(v[i].begin(),v[i].end());
	build(1,cnta,1);
	q.push(0);
	while(!q.empty())
	{
		int cc=q.front();q.pop();ans++;
		update(1,r[cc],1,cnta,1,p[cc]);
	}	
	printf("%d\n",ans-1);
	return 0;
}