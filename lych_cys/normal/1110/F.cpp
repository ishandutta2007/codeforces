#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 500009
#define M 2200009
using namespace std;

int n,m,now=1,fst[N],nxt[N],fa[N],len[N],dgr[N],lf[N],rg[N];
ll d[N],ans[N],mn[M],icr[M];
struct node{ int x,l,r,id; ll ans; }a[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
void build(int k,int l,int r){
	if (l==r){ mn[k]=(dgr[l]==1 && l>1)?d[l]:infll; return; }
	int mid=l+r>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
void mdy(int k,int l,int r,int x,int y,int z){
	if (x<=l && r<=y){ icr[k]+=z; mn[k]+=z; return; }
	int mid=l+r>>1;
	if (x<=mid) mdy(k<<1,l,mid,x,y,z);
	if (y>mid) mdy(k<<1|1,mid+1,r,x,y,z);
	mn[k]=min(mn[k<<1],mn[k<<1|1])+icr[k];	
}
ll getmin(int k,int l,int r,int x,int y){
	if (x<=l && r<=y) return mn[k];
	int mid=l+r>>1; ll ans=infll;
	if (x<=mid) ans=min(ans,getmin(k<<1,l,mid,x,y));
	if (y>mid) ans=min(ans,getmin(k<<1|1,mid+1,r,x,y));
	return ans+icr[k];
}
void dfs(int x){
	int y; lf[x]=rg[x]=x;
	for (y=fst[x]; y; y=nxt[y]){
		dfs(y); rg[x]=rg[y];
	}
}
void calc(int l,int r,int x){
	mdy(1,1,n,l,r,-x);
	if (l>1) mdy(1,1,n,1,l-1,x);
	if (r<n) mdy(1,1,n,r+1,n,x);
}
bool cmp(node a,node b){ return a.x<b.x; }
void solve(int x){
	int y;
	for (; now<=m && a[now].x==x; now++)
		a[now].ans=getmin(1,1,n,a[now].l,a[now].r);
	for (y=fst[x]; y; y=nxt[y]){
		calc(lf[y],rg[y],len[y]);
		solve(y);
		calc(lf[y],rg[y],-len[y]);
	}
}
int main(){
	n=read(); m=read();
	int i;
	for (i=2; i<=n; i++){
		fa[i]=read(); len[i]=read();
		dgr[i]++; dgr[fa[i]]++;
		d[i]=d[fa[i]]+len[i];
	}
	for (i=n; i>1; i--){
		nxt[i]=fst[fa[i]]; fst[fa[i]]=i;
	}
	for (i=1; i<=m; i++){
		a[i].x=read();
		a[i].l=read(); a[i].r=read();
		a[i].id=i;
	}
	sort(a+1,a+m+1,cmp);
	build(1,1,n);
	dfs(1); solve(1);
	for (i=1; i<=m; i++) ans[a[i].id]=a[i].ans;
	for (i=1; i<=m; i++) printf("%lld\n",ans[i]);
	return 0;
}