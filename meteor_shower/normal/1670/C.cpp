#include<cstdio>
const int N=1e5+5;
const int Mod=1e9+7;
int n,a[N],b[N],d[N];
int fa[N];
int fra[N],frb[N];
bool know[N];
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
inline int Find(const int u){
	return fa[u]==u?u:fa[u]=Find(fa[u]);
}
inline void Init(){
	n=Read();
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		a[i]=Read();
	for(int i=1;i<=n;i++){
		b[i]=Read();
		frb[b[i]]=i;
	}
	for(int i=1;i<=n;i++){
		know[i]=Read();
		if(a[i]==b[i]) know[i]=1;
	}
	return ;
}
inline void Solve(){
	for(int i=1;i<=n;i++){
		int fu=Find(i);
		int fv=Find(frb[a[i]]);
		fa[fu]=fv;
		know[fv]=know[fv]||know[fu];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		if(Find(i)!=i) continue ;
		if(!know[i]) ans=2*ans%Mod;
	}
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