#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;i++)
#define per(i,r,l) for (int i=r;i>=l;i--)
#define ll long long
#define mo 1000000007
#define N 200005
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
ll pw(ll x,ll y){
	ll t=1;
	for (;y;y>>=1){
		if (y&1) t=t*x%mo;
		x=x*x%mo;
	}
	return t;
}
int n,NI[N],mu[N],phi[N],p[N],pr;
bool u[N];
void getp(int n){
	rep(i,1,n) NI[i]=pw(i,mo-2);
	phi[1]=1;
	mu[1]=1;
	rep(i,2,n){
		if (!u[i]){p[++pr]=i;phi[i]=i-1;mu[i]=-1;}
		rep(j,1,pr){
			if (i*p[j]>n) break;
			u[i*p[j]]=1;
			if (i%p[j]==0){phi[i*p[j]]=phi[i]*p[j];break;}
			else phi[i*p[j]]=phi[i]*phi[p[j]],mu[i*p[j]]=-mu[i];
		}
	}
}
int tmp[N*2],ts,a[N],Z,nxt[N*2],hed[N],too[N*2],nedge,L[N],dfn,anc[N][18],depth[N];
void ae(int x,int y){
	tmp[++ts]=x;
	nxt[++nedge]=hed[x];
	hed[x]=nedge;
	too[nedge]=y;
}
void add(int x,int y){
	if (x==y) return;
	ae(x,y),ae(y,x);
}
inline bool cmp(const int &A,const int &B){
	return (L[A]<L[B]);
}
void dfs(int x,int l){
	L[x]=++dfn;
	depth[x]=depth[l]+1;
	anc[x][0]=l;
	for (int i=hed[x];i;i=nxt[i]){
		int y=too[i];
		if (y==l) continue;
		dfs(y,x);
	}
}
ll ps[N],D[N];
int FA[N];
void DFS(int x,int l){
	if (a[x]%Z==0) ps[x]=phi[a[x]]; else ps[x]=0;
	for (int i=hed[x];i;i=nxt[i]){
		int y=too[i];
		if (y==l) continue;
		DFS(y,x);
		FA[y]=x;
		D[y]=depth[y]-depth[x];
		ps[x]+=ps[y];
		if (ps[x]>=mo) ps[x]-=mo;
	}
}
void lca_init(){
	rep(j,1,17)
		rep(i,1,n)
			anc[i][j]=anc[anc[i][j-1]][j-1];
}
int lca_get(int x,int y){
	if (depth[x]<depth[y]) std::swap(x,y);
	per(i,17,0)
		if (depth[anc[x][i]]>=depth[y]) x=anc[x][i];
	if (x==y) return x;
	per(i,17,0)
		if (anc[x][i]!=anc[y][i]) x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
int x,y,w[N],top,root,stk[N],s,c[N];
ll f[N],g[N],ans;
int main(){
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	getp(n);
	rep(i,1,n) getint(a[i]),w[a[i]]=i;
	rep(i,2,n){
		getint(x),getint(y);
		add(x,y);
	}
	dfs(1,0);
	lca_init();
	rep(i,1,n) hed[i]=0;
	rep(z,1,n){
		s=0;
		Z=z;
		for (int j=z;j<=n;j+=z) c[++s]=w[j];
		std::sort(c+1,c+s+1,cmp);
		stk[top=1]=c[1];
		nedge=0;
		ts=0;
		rep(i,2,s){
			int u=lca_get(c[i],stk[top]);
			while (depth[u]<depth[stk[top-1]]) add(stk[top-1],stk[top]),--top;
			add(u,stk[top--]);
			if (stk[top]!=u) stk[++top]=u;
			if (stk[top]!=c[i]) stk[++top]=c[i];
		}
		while (--top) add(stk[top],stk[top+1]);
		std::sort(tmp+1,tmp+ts+1);
		ts=std::unique(tmp+1,tmp+ts+1)-tmp-1;
		root=tmp[1];
		rep(i,2,ts)
			if (depth[tmp[i]]<depth[root]) root=tmp[i];
		DFS(root,0);
		rep(i,1,ts)
			if (tmp[i]!=root) (f[z]+=D[tmp[i]]*ps[tmp[i]]%mo*(ps[root]-ps[tmp[i]]))%=mo;
		rep(i,1,ts) hed[tmp[i]]=0;
	}
	rep(z,1,n)
		for (int i=1;i<=(n/z);++i)
			(g[z]+=f[i*z]*mu[i])%=mo;
	ans=0;
	rep(z,1,n) (ans+=g[z]*z%mo*NI[phi[z]])%=mo;
	(ans+=mo)%=mo;
	(ans<<=1)%=mo;
	ans=ans*NI[n]%mo*NI[n-1]%mo;
	printf("%d\n",(int)ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}