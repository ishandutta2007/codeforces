#include<cstdio>
#include<cstring>
const int N=10;
const int M=25;
int n,m,Chose[N],tot;
int Ver[M],Uer[M];
int Answer;
bool Vis[N][N];
inline int Read(){
	char ch;int f=1,x;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') f=-1;x=ch^48;
	while((ch=getchar())>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline int Max(const int x,const int y){
	return x>y?x:y;
}
inline void Check(){
	memset(Vis,0,sizeof(Vis));
	tot=0;
	for(register int i=1;i<=m;i++){
		int u=Uer[i];
		int v=Ver[i];
		int ku=Chose[u];
		int kv=Chose[v];
		if(Vis[ku][kv]) tot++;
		Vis[ku][kv]=Vis[kv][ku]=1;
	}
	Answer=Max(Answer,m-tot);
}
inline void Dfs(const int x){
	if(x==n+1) return Check();
	for(register int i=1;i<=6;i++){
		Chose[x]=i;
		Dfs(x+1);
	}
}
inline void Init(){
	n=Read();
	m=Read();
	for(register int i=1;i<=m;i++){
		Uer[i]=Read();
		Ver[i]=Read();
	}
}
int main(){
	Init();Dfs(1);
	printf("%d\n",Answer);
	return 0;
}