#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=2e5+5;
const int Z=18;
const int Mod=998244353;
const int INV2=(Mod+1)/2;
int n;
int Head[N],Ver[N<<1],Nxt[N<<1],cnt_edge=-1;
int dfn[N],clk;
int a[N];
vector<int>in[N];
int fa[N][Z],dep[N];
inline int Read(){
	char ch;
	int f=1;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void print(int x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(int x,char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline void Add(int u,int v){
	++cnt_edge;
	Ver[cnt_edge]=v;
	Nxt[cnt_edge]=Head[u];
	Head[u]=cnt_edge;
	return ;
}
inline void Add_Edge(int u,int v){
	Add(u,v);
	Add(v,u);
	return ;
}
inline void Dfs(int u){
	dfn[u]=++clk;
	dep[u]=dep[fa[u][0]]+1;
	for(int i=1;i<Z;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=Head[u];i!=-1;i=Nxt[i]){
		int v=Ver[i];
		if(v==fa[u][0]) continue ;
		fa[v][0]=u;
		Dfs(v);
	}
	return ;
}
inline void Init(){
	memset(Head,-1,sizeof(Head));
	n=Read();
	for(int i=1;i<=n;i++){
		int x=Read();
		a[i]=x;
		for(int j=2;j*j<=x;j++){
			if(x%j) continue ;
			in[j].push_back(i);
			while(x%j==0) x/=j;
		}
		if(x>1) in[x].push_back(i);
	}
	for(int i=1;i<n;i++){
		int u=Read();
		int v=Read();
		Add_Edge(u,v);
	}
	return Dfs(1);
}
inline void Swap(int&x,int&y){
	int tmp=x;
	x=y;y=tmp;
	return ;
}
inline int LCA(int u,int v){
	if(dep[u]<dep[v]) Swap(u,v);
	for(int i=Z-1;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if(u==v) return u;
	for(int i=Z-1;i>=0;i--)
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
int st[N],top;
inline void Insert(int u){
	Head[u]=-1;
	if(top<=1){st[++top]=u;return ;}
	int lca=LCA(u,st[top]);
	if(lca==st[top]){st[++top]=u;return ;}
	while(top>1&&dfn[lca]<=dfn[st[top-1]]){
		Add_Edge(st[top-1],st[top]);
		--top;
	}
	if(lca!=st[top]){
		Head[lca]=-1;
		Add_Edge(lca,st[top]);
		st[top]=lca;
	}
	st[++top]=u;
	return ;
}
inline int addv(int x,int y){
	int s=x+y;
	if(s>=Mod) s-=Mod;
	return s;
}
inline int subv(int x,int y){
	int s=x-y;
	if(s<0) s+=Mod;
	return s;
}
inline void add(int&x,int y){
	x=addv(x,y);
	return ;
}
inline void sub(int&x,int y){
	x=subv(x,y);
	return ;
}
int sum[N],cnt[N];
int ans;
inline int C(int x){
	return 1ll*x*(x-1)/2%Mod;
}
inline void Dfs1(int u,int prm){
	sum[u]=0;
	cnt[u]=(a[u]%prm==0);
	for(int i=Head[u];i!=-1;i=Nxt[i]){
		int v=Ver[i];
		if(dep[v]<dep[u]) continue ;
		Dfs1(v,prm);
		add(sum[u],addv(sum[v],1ll*cnt[v]*(dep[v]-dep[u])%Mod));
		add(cnt[u],cnt[v]);
	}
	return ;
}
inline void Dfs2(int u,int prm,int upsum,int upcnt){
	//printf("u=%d sum=%d cnt=%d upsum=%d upcnt=%d\n",u,sum[u],cnt[u],upsum,upcnt);
	int sumC=0;
	for(int i=Head[u];i!=-1;i=Nxt[i]){
		int v=Ver[i];
		if(dep[v]<dep[u]) continue ;
		add(sumC,C(cnt[v]));
	}
	add(ans,1ll*upsum*subv(C(cnt[u]),sumC)%Mod);
	for(int i=Head[u];i!=-1;i=Nxt[i]){
		int v=Ver[i];
		if(dep[v]<dep[u]) continue ;
		int cntt=subv(C(cnt[u]-cnt[v]+upcnt),addv(subv(sumC,C(cnt[v])),C(upcnt)));
		add(ans,1ll*addv(sum[v],1ll*cnt[v]*(dep[v]-dep[u])%Mod)*cntt%Mod);
	}
	for(int i=Head[u];i!=-1;i=Nxt[i]){
		int v=Ver[i];
		if(dep[v]<dep[u]) continue ;
		int summ=subv(addv(sum[u],upsum),addv(sum[v],1ll*cnt[v]*(dep[v]-dep[u])%Mod));
		int cntt=subv(addv(cnt[u],upcnt),cnt[v]);
		Dfs2(v,prm,addv(summ,1ll*cntt*(dep[v]-dep[u])%Mod),cntt);
	}
	return ;
}
inline bool Cmp(int x,int y){
	return dfn[x]<dfn[y];
}
inline void Work(int prm){
	if(!in[prm].size()) return ;
	top=0;
	cnt_edge=-1;
	sort(in[prm].begin(),in[prm].end(),Cmp);
	if(in[prm][0]!=1){
		Head[1]=-1;
		st[top=1]=1;
	}
	for(int i=0;i<in[prm].size();i++)
		Insert(in[prm][i]);
	while(top>1){
		Add_Edge(st[top-1],st[top]);
		top--;
	}
	Dfs1(1,prm);
	Dfs2(1,prm,0,0);
	return ;
}
inline void Solve(){
	for(int i=2;i<=N-5;i++)
		Work(i);
	return Print(ans);
}
int main(){
	Init();
	Solve();
	return 0;
}