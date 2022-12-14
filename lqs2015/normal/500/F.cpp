#include<bits/stdc++.h>
using namespace std;
const int maxn=4000;
int dp[8888][4444],tr[44][4444],q;
int n,k,l[22222],r[22222],cnt,v[22222],w[22222],tim,Q,tp,x,y,num,t[33333],sz,a[22222],z;
bool f;
map<int,int> mp;
vector<pair<int,int> > tree[1<<14];
void update(int beg,int en,int l,int r,int node,int i)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		tree[node].push_back(make_pair(v[i],w[i]));
		return;
	}
	int mid=(l+r)>>1;
	update(beg,en,l,mid,node<<1,i);
	update(beg,en,mid+1,r,(node<<1)|1,i);
}
void dfs(int l,int r,int node,int dep)
{
	for (int i=1;i<=maxn;i++) tr[dep][i]=tr[dep-1][i];
	for (int i=0;i<tree[node].size();i++)
	{
		int v=tree[node][i].first,w=tree[node][i].second;
		for (int j=maxn;j>=w;j--) tr[dep][j]=max(tr[dep][j],tr[dep][j-w]+v);
	}
	if (l==r)
	{
		for (int i=1;i<=maxn;i++) dp[l][i]=tr[dep][i];
		return;
	}
	int mid=(l+r)>>1;
	dfs(l,mid,node<<1,dep+1);
	dfs(mid+1,r,(node<<1)|1,dep+1);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&w[i],&v[i],&x);
		a[++cnt]=x;a[++cnt]=x+k;
		l[i]=x;r[i]=x+k;
	}
	sort(a+1,a+cnt+1);
	cnt=unique(a+1,a+cnt+1)-a-1;
	for (int i=1;i<=cnt;i++)
	{
		mp[a[i]]=i;
	}
	for (int i=1;i<=n;i++)
	{
		l[i]=mp[l[i]];r[i]=mp[r[i]];
	}
	sz=1;
	while(sz<cnt) sz*=2;
	for (int i=1;i<=n;i++)
	{
		update(l[i],r[i]-1,1,sz,1,i);
	}
	dfs(1,sz,1,1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		z=lower_bound(a+1,a+cnt+1,x)-a;
		if (z>cnt || a[z]>x) z--;
		if (!z) printf("0\n");
		else printf("%d\n",dp[z][y]);
	}
	return 0;
}