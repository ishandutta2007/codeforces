#include<bits/stdc++.h>
using namespace std;
const int p=1e7+19,q=1e9+7;
int dp[1<<15][1111],ans;
int n,k,l[22222],r[22222],cnt,v[22222],w[22222],tim,Q,tp,x,num,t[33333],sz;
bool f;
vector<pair<int,int> > tree[1<<15];
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
void dfs(int l,int r,int node)
{
	for (int i=1;i<=k;i++) dp[node][i]=dp[node>>1][i];
	for (int i=0;i<tree[node].size();i++)
	{
		int v=tree[node][i].first,w=tree[node][i].second;
		for (int j=k;j>=w;j--) dp[node][j]=max(dp[node][j],dp[node][j-w]+v);
	}
	if (l==r) return;
	int mid=(l+r)>>1;
	dfs(l,mid,node<<1);
	dfs(mid+1,r,(node<<1)|1);
}
int main()
{
	scanf("%d%d",&n,&k);
	sz=1<<14;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&v[i],&w[i]);
		l[i]=1;
	}
	cnt=n;
	tim=1;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			cnt++;
			scanf("%d%d",&v[cnt],&w[cnt]);
			l[cnt]=tim+1;
			f=0;
		}
		else if (tp==2)
		{
			scanf("%d",&x);
			r[x]=tim;
			f=0;
		}
		else
		{
			++num;
			if (f) t[num]=tim;
			else t[num]=++tim;
			f=1;
		}
	}
	for (int i=1;i<=cnt;i++)
	{
		if (!r[i]) r[i]=tim;
		update(l[i],r[i],1,sz,1,i);
	}
	dfs(1,sz,1);
	for (int i=1;i<=num;i++)
	{
		ans=0;
		for (int j=k;j>=1;j--)
		{
			ans=(1ll*ans*p+dp[sz-1+t[i]][j])%q;
		}
		printf("%d\n",ans);
	}
	return 0;
}