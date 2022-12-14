#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
int cnt;
struct line
{
	long long k,b;
}le[111111];
bool cmp(line &x,line &y,long long c)
{
	return (x.k*c+x.b<y.k*c+y.b);
}
long long catch_val(line &x,long long c)
{
	return x.k*c+x.b;
}
vector<int> g[111111];
int n,x,y,rt[111111],l[11111111],r[11111111],tree[11111111],sz;
long long a[111111],b[111111],dp[111111];
int add(int nw,int lp,int rp,int cur)
{
	if (!nw)
	{
		nw=++sz;
		tree[nw]=cur;
		return nw;
	}
	if (cmp(le[cur],le[tree[nw]],lp)) swap(tree[nw],cur);
	if (lp==rp) return nw;
	if (cmp(le[tree[nw]],le[cur],rp)) return nw;
	int mid=(lp+rp)>>1;
	if (cmp(le[cur],le[tree[nw]],mid)) 
	{
		l[nw]=add(l[nw],lp,mid,tree[nw]);
		tree[nw]=cur;
	}
	else r[nw]=add(r[nw],mid+1,rp,cur);
	return nw;
}
long long query(int nw,int lp,int rp,int x)
{
	if (!nw) return 1e18;
	if (lp==rp) return catch_val(le[tree[nw]],x);
	int mid=(lp+rp)>>1;
	if (x>mid) return min(query(r[nw],mid+1,rp,x),catch_val(le[tree[nw]],x));
	return min(query(l[nw],lp,mid,x),catch_val(le[tree[nw]],x));
}
int merge(int x,int y,int lp,int rp)
{
	if (!x || !y) return x^y;
	if (lp==rp)
	{
		if (cmp(le[tree[x]],le[tree[y]],lp)) return x;
		return y;
	}
	int pos=++sz,mid=(lp+rp)>>1;
	l[pos]=merge(l[x],l[y],lp,mid);r[pos]=merge(r[x],r[y],mid+1,rp);
	pos=add(pos,lp,rp,tree[x]);pos=add(pos,lp,rp,tree[y]);
	return pos;
}
void dfs(int i,int fa)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		rt[i]=merge(rt[i],rt[to],-maxn,maxn);
	}
	if (!rt[i]) dp[i]=0;
	else dp[i]=query(rt[i],-maxn,maxn,a[i]);	
	le[++cnt]=(line){b[i],dp[i]};
	rt[i]=add(rt[i],-maxn,maxn,cnt);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	le[0]=(line){0,10000000000000000ll};
	dfs(1,0);
	for (int i=1;i<=n;i++) printf("%lld ",dp[i]);
	printf("\n");
	return 0;
}