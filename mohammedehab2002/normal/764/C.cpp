#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005],t;
int dp[100005],s[100005],st[100005],en[100005],col[100005],par[100005];
long long tree[1000005];
void dfs(int node,int pnode)
{
	s[node]=1;
	par[node]=pnode;
	dp[node]=1;
	t.push_back(node);
	st[node]=t.size()-2;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		{
			dfs(v[node][i],node);
			if (!dp[v[node][i]] || col[node]!=col[v[node][i]])
			dp[node]=0;
			s[node]+=s[v[node][i]];
		}
	}
	t.push_back(node);
	en[node]=t.size();
}
void build(int node,int start,int end)
{
    if (start==end)
    tree[node]=col[t[start]];
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
long long query(int node,int start,int end,int l,int r)
{
    if (r<start || end<l)
    return 0LL;
    if (l<=start && end<=r)
    return tree[node];
    int mid=(start+end)/2;
    long long p1=query(2*node,start,mid,l,r);
    long long p2=query(2*node+1,mid+1,end,l,r);
    return (p1+p2);
}
int main()
{
	int n;
	cin >> n;
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=1;i<=n;i++)
	scanf("%d",&col[i]);
	dfs(1,0);
	build(1,0,t.size()-1);
	for (int i=1;i<=n;i++)
	{
		bool b=1;
		for (int x=0;x<v[i].size();x++)
		{
			if (v[i][x]!=par[i])
			b&=dp[v[i][x]];
		}
		long long a=query(1,0,t.size()-1,0,st[i]);
		a+=query(1,0,t.size()-1,en[i],t.size()-1);
		a/=2;
		long long cmp=(n-s[i]);
		long long c=col[par[i]];
		cmp*=c;
		if (a==cmp && b)
		{
			cout << "YES\n" << i;
			return 0;
		}
	}
	cout << "NO";
}