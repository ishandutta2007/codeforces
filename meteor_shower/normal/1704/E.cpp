#include<cstdio>
#include<cstring>
typedef long long LL;
const int N=1005;
const int Mod=998244353;
int Head[N],Nxt[N],Ver[N],ind[N],cnt_edge;
int f[N][N],n,m,g[N][N],a[N];
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
inline void Add_Edge(const int u,const int v){
	++cnt_edge;
	Ver[cnt_edge]=v;
	Nxt[cnt_edge]=Head[u];
	Head[u]=cnt_edge;
	++ind[v];
	return ;
}
inline int addv(const int x,const int y){
	int s=x+y;
	if(s>=Mod) s-=Mod;
	return s;
}
inline int subv(const int x,const int y){
	int s=x-y;
	if(s<0) s+=Mod;
	return s;
}
inline void add(int&x,const int y){
	x=addv(x,y);
	return ;
}
inline void sub(int&x,const int y){
	x=subv(x,y);
	return ;
}
inline void Dfs(const int u){
	for(int i=Head[u];i!=-1;i=Nxt[i]){
		int v=Ver[i];
		for(int j=0;j<=n;j++){
			if(f[v][j+1]+f[u][j]>=Mod||g[u][j]) g[v][j+1]=1;
			add(f[v][j+1],f[u][j]);
		}
		--ind[v];
		if(ind[v]==0) Dfs(v);
	}
	return ;
}
inline void Init(){
	memset(Head,-1,sizeof(Head));
	memset(ind,0,sizeof(ind));
	cnt_edge=-1;
	n=Read();m=Read();
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			f[i][j]=g[i][j]=0;
	for(int i=1;i<=n;i++)
		a[i]=Read();
	for(;m;m--){
		int u=Read(),v=Read();
		Add_Edge(v,u);
	}
	for(int i=1;i<=n;i++)
		if(ind[i]==0){
			f[i][0]=1;
			return Dfs(i);
		}
}
int b[N],c[N],ans;
inline void Solve(){
	for(int i=0;i<=n;i++)
		b[i]=c[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++){
			LL v=1ll*a[i]*f[i][j];
			if(v+b[j]>=Mod) c[j]=1;
			if(g[i][j]) c[j]=1;
			add(b[j],v%Mod);
		}
	bool flg=c[0];
	int ss=b[0];
	ans=0;
	for(int i=1;i<=n;i++){
		if(flg||ss) sub(ss,1),ans=i;
		if(ss+b[i]>=Mod) flg=1;
		if(c[i]) flg=1;
		add(ss,b[i]);
	}
	if(ss||flg) ans=addv(n,ss);
	Print(ans);
	return ;
}
int T;
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}