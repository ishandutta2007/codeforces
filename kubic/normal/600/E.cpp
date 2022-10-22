#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
#define mid (l+r>>1)
int n,a[N],rt[N];ll ans[N];vector<int> e[N];
int cntS,bin[N*20];struct Seg {int mx,ch[2];ll v;}sg[N*20];
int New() {int p=bin[0]?bin[bin[0]--]:++cntS;sg[p]=(Seg) {0,{0,0},0};return p;}
void pu(int p)
{
	int ch[2]={sg[p].ch[0],sg[p].ch[1]};sg[p].mx=max(sg[ch[0]].mx,sg[ch[1]].mx);
	sg[p].v=0;if(sg[p].mx==sg[ch[0]].mx) sg[p].v+=sg[ch[0]].v;
	if(sg[p].mx==sg[ch[1]].mx) sg[p].v+=sg[ch[1]].v;
} 
void upd(int &p,int l,int r,int x)
{
	if(!p) p=New();if(l==r) {++sg[p].mx;sg[p].v=x;return;}
	if(x<=mid) upd(sg[p].ch[0],l,mid,x);else upd(sg[p].ch[1],mid+1,r,x);pu(p);
}
int merge(int pL,int pR,int l,int r)
{
	if(!pL || !pR) return pL|pR;if(l==r) {sg[pL].mx+=sg[pR].mx;return pL;}
	sg[pL].ch[0]=merge(sg[pL].ch[0],sg[pR].ch[0],l,mid);
	sg[pL].ch[1]=merge(sg[pL].ch[1],sg[pR].ch[1],mid+1,r);
	pu(pL);bin[++bin[0]]=pR;return pL;
}
void dfs(int u,int f)
{
	upd(rt[u],1,n,a[u]);
	for(int i=0,v;i<e[u].size();++i)
	{v=e[u][i];if(v!=f) dfs(v,u),rt[u]=merge(rt[u],rt[v],1,n);}ans[u]=sg[rt[u]].v;
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	dfs(1,0);for(int i=1;i<=n;++i) printf("%lld ",ans[i]);return 0;
}