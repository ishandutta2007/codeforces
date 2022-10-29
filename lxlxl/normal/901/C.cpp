#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 310000;
ll cal(ll a,ll b){return (a+b)*(b-a+1ll)/2;}

int n,m,q;
vector<int>V[maxn];

struct edge
{
	int y,nex;
}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y){a[++len]=(edge){y,fir[x]};fir[x]=len;}
int dfn[maxn],id,dep[maxn],t[maxn];
void dfs(const int x,const int fa,const int dd)
{
	dfn[x]=++id; dep[x]=dd; t[dd]=x;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa)
	{
		if(dep[y]<dep[x]&&dfn[y])
		{
			int mx=1,mn=n;
			for(int j=dep[y];j<=dep[x];j++)
				mx=max(mx,t[j]),mn=min(mn,t[j]);
			V[mx].push_back(mn);
		}
		else if(!dfn[y]) dfs(y,x,dd+1);
	}
}

struct node
{
	int l,r,i;
	friend inline bool operator <(const node x,const node y) { return x.r<y.r; }
}Q[maxn];
ll ans[maxn];

struct segment
{
	ll b,k;
}seg[maxn<<2];
int lx,rx;
ll fb,fk;
void upd(const int x,const int l,const int r)
{
	if(rx<l||r<lx) return;
	if(lx<=l&&r<=rx)
	{
		seg[x].k+=fk,seg[x].b+=fb;
		return;
	}
	int mid=l+r>>1,lc=x<<1,rc=lc|1;
	upd(lc,l,mid); upd(rc,mid+1,r);
}
ll re;
int loc;
void query(const int x,const int l,const int r,ll k,ll b)
{
	k+=seg[x].k,b+=seg[x].b;
	if(l==r)
	{
		re=b-k*(ll)l;
		return;
	}
	int mid=l+r>>1,lc=x<<1,rc=lc|1;
	if(loc<=mid) query(lc,l,mid,k,b);
	else query(rc,mid+1,r,k,b);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		ins(x,y); ins(y,x);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i,0,1);
	
	scanf("%d",&q);
	for(int i=1;i<=q;i++) scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].i=i;
	sort(Q+1,Q+q+1);
	
	int now=1,nowq=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<V[i].size();j++) now=max(now,V[i][j]+1);
		fb=i+1ll,fk=1ll,lx=now,rx=i; upd(1,1,n);
		fb=i-now+1,fk=0; lx=1,rx=now-1; if(lx<=rx) upd(1,1,n);
		while(nowq<=q&&Q[nowq].r==i)
		{
			re=0;
			loc=Q[nowq].l; query(1,1,n,0,0);
			ans[Q[nowq].i]=re; nowq++;
		}
	}
	
	for(int i=1;i<=q;i++) printf("%I64d\n",ans[i]);
	
    return 0;
}