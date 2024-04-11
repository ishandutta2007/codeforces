#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 800009
#define M 800009
using namespace std;

int n,m,fst[N],nxt[N],fa[N],a[N],b[N],d[N],dfn[N],f[20][M],lg2[M];
struct node{ int x,y; }T[M];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
void dfs(int x){
	int y; f[0][dfn[x]=++m]=d[x];
	for (y=fst[x]; y; y=nxt[y]){
		d[y]=d[x]+1; dfs(y); f[0][++m]=d[x];
	}
}
int dist(int x,int y){
	int u=dfn[x],v=dfn[y]; if (u>v) swap(u,v);
	int k=lg2[v-u+1];
	//cerr<<"dist:"<<x<<' '<<y<<' '<<d[x]+d[y]-(min(f[k][u],f[k][v-(1<<k)+1])<<1)<<'\n';
	return d[x]+d[y]-(min(f[k][u],f[k][v-(1<<k)+1])<<1);
}
node mrg(int x,int y,int z){
	if (x==-1 || y==-1 || z==-1) return (node){-1,-1};
	int a=dist(x,y),b=dist(x,z),c=dist(y,z);
	if (b<c){ swap(b,c); swap(x,y); }
	if (a<b){ swap(a,b); swap(y,z); }
	if (a!=b+c) return (node){-1,-1}; return (node){x,y};	
}
node mrg(node u,node v){
	node tmp=mrg(u.x,u.y,v.x); return mrg(tmp.x,tmp.y,v.y);
}
void build(int k,int l,int r){
	if (l==r){ T[k]=(node){a[l],a[l]}; return; }
	int mid=l+r>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r);
	T[k]=mrg(T[k<<1],T[k<<1|1]);
	//cerr<<l<<' '<<r<<' '<<T[k].x<<' '<<T[k].y<<'\n';
}
void ins(int k,int l,int r,int x){
	if (l==r){ T[k]=(node){a[l],a[l]}; return; }
	int mid=l+r>>1;
	if (x<=mid) ins(k<<1,l,mid,x); else ins(k<<1|1,mid+1,r,x);
	T[k]=mrg(T[k<<1],T[k<<1|1]);	
	//cerr<<l<<' '<<r<<' '<<T[k].x<<' '<<T[k].y<<'\n';
}
int main(){
	n=read();
	int i;
	for (i=1; i<=n; i++){
		b[i]=read()+1; a[b[i]]=i;
	}
	for (i=2; i<=n; i++){
		fa[i]=read();
		nxt[i]=fst[fa[i]]; fst[fa[i]]=i;	
	}
	dfs(1);
	for (i=1; i<=19; i++)
		for (int j=1; j<=m; j++){
			f[i][j]=f[i-1][j];
			if (j+(1<<i-1)<=m) f[i][j]=min(f[i][j],f[i-1][j+(1<<i-1)]);	
		}
	for (i=2; i<=m; i++) lg2[i]=lg2[i/2]+1;
	build(1,1,n);
	int cas=read();
	while (cas--){
		i=read();
		if (i==1){
			int x=read(),y=read();
			swap(b[x],b[y]); a[b[x]]=x; a[b[y]]=y;
			ins(1,1,n,b[x]); ins(1,1,n,b[y]);
		} else{
			if (T[1].x!=-1){ printf("%d\n",n); continue; }
			int k=1,l=1,r=n,mid; node now=(node){a[1],a[1]},tmp;
			while (l<r){
				mid=l+r>>1;
				tmp=now; now=mrg(now,T[k<<1]);
				if (now.x!=-1){
					k=k<<1|1; l=mid+1;	
				} else{
					now=tmp; k=k<<1; r=mid;
				}
			}
			printf("%d\n",l-1);
		}
	}
	return 0;
}