#include<cstdio>
#include<cstring>
const int N=2e5+5;
int ind[N],oud[N],n,m,indd[N];
int Head[N],Ver[N],Nxt[N],cnt_edge=-1;
int ans,f[N];
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
	oud[u]++;
	ind[v]++;
	indd[v]++;
	Ver[cnt_edge]=v;
	Nxt[cnt_edge]=Head[u];
	Head[u]=cnt_edge;
	return ;
}
inline int Max(const int x,const int y){
	return x>y?x:y;
}
inline int Min(const int x,const int y){
	return x<y?x:y;
}
inline void Dfs(const int u){
	indd[u]=-1;
	f[u]++;
	ans=Max(ans,f[u]);
	if(oud[u]<=1) return ;
	for(int i=Head[u];i!=-1;i=Nxt[i]){
		int v=Ver[i];
		if(ind[v]==1) continue ;
		f[v]=Max(f[v],f[u]);
		indd[v]--;
		if(!indd[v]) Dfs(v);
	}
	return ;
}
inline void Init(){
	memset(Head,-1,sizeof(Head));
	n=Read();
	for(m=Read();m;m--){
		int u=Read();
		int v=Read();
		Add_Edge(u,v);
	}
	for(int i=1;i<=n;i++){
		if(oud[i]==1){
			int u=Ver[Head[i]];
			indd[u]--;
		}
	}
	//for(int i=1;i<=n;i++)
		//printf("%d %d\n",ind[i],oud[i]);
	return ;
}
inline void Solve(){
	for(int i=1;i<=n;i++)
		if(indd[i]==0||ind[i]==1) Dfs(i);
	Print(ans);
	return ;
}
int main(){
	Init();
	Solve();
	return 0;
}