#include<cstdio>
#include<cstring>
const int N=1e5+5;
const int M=2e5+5;
const int Z=17;
int n,m,uu[M],vv[M];
int fa[N][Z],dep[N];
int Head[N],Ver[M],Nxt[M],cnt_edge=-1;
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
inline void print(const int x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(const int x,const char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline void Add(const int u,const int v){
	++cnt_edge;
	Ver[cnt_edge]=v;
	Nxt[cnt_edge]=Head[u];
	Head[u]=cnt_edge;
	return ;
}
inline void Add_Edge(const int u,const int v){
	Add(u,v);
	Add(v,u);
	return ;
}
int dsu[N];
inline int Find(const int u){
	return dsu[u]==u?u:dsu[u]=Find(dsu[u]);
}
inline void Init(){
	memset(Head,-1,sizeof(Head));
	n=Read();m=Read();
	for(int i=1;i<=n;i++)
		dsu[i]=i;
	for(int i=1;i<=m;i++){
		uu[i]=Read();
		vv[i]=Read();
		int fu=Find(uu[i]),fv=Find(vv[i]);
		if(fu==fv) continue ;
		dsu[fu]=fv;
		Add_Edge(uu[i],vv[i]);
	}
	return ;
}
inline void Dfs(const int u){
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
inline int Jump(int u,const int dist){
	for(int i=0;i<Z;i++)
		if(dist&(1<<i)) u=fa[u][i];
	return u;
}
inline void Swap(int&x,int&y){
	int tmp=x;
	x=y;y=tmp;
	return ;
}
int add[N],sub[N];
inline void AddTree(){
	Dfs(1);
	for(int i=1;i<=m;i++){
		if(dep[uu[i]]>dep[vv[i]]) Swap(uu[i],vv[i]);
		if(fa[vv[i]][0]==uu[i]) continue ;
		if(Jump(vv[i],dep[vv[i]]-dep[uu[i]])==uu[i]){
			add[Jump(vv[i],dep[vv[i]]-dep[uu[i]]-1)]++;
			sub[vv[i]]++;
		}
		else{
			add[1]++;
			sub[uu[i]]++;
			sub[vv[i]]++;
		}
	}
	return ;
}
bool ans[N];
inline void Dfs(const int u,int ss){
	ss+=add[u]-sub[u];
	if(ss==0) ans[u]=1;
	for(int i=Head[u];i!=-1;i=Nxt[i]){
		int v=Ver[i];
		if(v==fa[u][0]) continue ;
		Dfs(v,ss);
	}
	return ;
}
inline void Solve(){
	AddTree();
	Dfs(1,0);
	for(int i=1;i<=n;i++)
		putchar(ans[i]+'0');
	putchar('\n');
	return ;
}
int main(){
	Init();
	Solve();
	return 0;
}