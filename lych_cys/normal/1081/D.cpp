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
#define N 200009
using namespace std;

int n,m,cnt,tot,ans,dgr[N],p[N],h[N],fst[N],pnt[N<<1],len[N<<1],nxt[N<<1],fa[N];
pair<int,pii >a[N]; bool vis[N],ban[N],bo[N];
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
void add(int x,int y,int z){
	dgr[x]++;
	pnt[++tot]=y; len[tot]=z; nxt[tot]=fst[x]; fst[x]=tot;
}
void ins(int x,int y,int z){ add(x,y,z); add(y,x,z); }
int getfa(int x){ return x==fa[x]?x:fa[x]=getfa(fa[x]); }
void dfs(int x){
	int i,y; vis[x]=1;
	for	(i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (!ban[y] && !vis[y]){
			ans=max(ans,len[i]); dfs(y);
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&cnt);
	int i,x,y,z;
	for (i=1; i<=cnt; i++){
		scanf("%d",&p[i]); bo[p[i]]=1;	
	}
	for (i=1; i<=m; i++){
		scanf("%d%d%d",&x,&y,&z);
		a[i]=mpr(z,mpr(x,y));	
	}
	sort(a+1,a+m+1);
	for (i=1; i<=n; i++) fa[i]=i;
	for (i=1; i<=m; i++){
		x=getfa(a[i].se.fi); y=getfa(a[i].se.se);
		if (x!=y){
			fa[x]=y; ins(a[i].se.fi,a[i].se.se,a[i].fi);
		}
	}
	int head=0,tail=0;
	for (i=1; i<=n; i++) if (dgr[i]==1 && !bo[i]){
		h[++tail]=i; ban[i]=1;
	}
	while (head<tail){
		x=h[++head];
		for (i=fst[x]; i; i=nxt[i]){
			y=pnt[i];
			if (!ban[y]){
				dgr[y]--;
				if (dgr[y]==1 && !bo[y]){
					ban[y]=1; h[++tail]=y;
				}
			}
		}
	}
	dfs(p[1]);//for (i=1; i<=cnt; i++) dfs(p[i]);
	while (cnt--) printf("%d%c",ans,cnt?' ':'\n');
	return 0;
}