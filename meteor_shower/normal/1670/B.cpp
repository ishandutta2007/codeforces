#include<cstdio>
const int N=1e5+5;
const int Z=26;
char s[N];
bool vis[Z];
int n,k;
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
inline void Init(){
	n=Read();
	for(int i=0;i<Z;i++)
		vis[i]=0;
	scanf("%s",s+1);
	for(k=Read();k;k--){
		char ch;
		while((ch=getchar())<'a'||ch>'z');
		vis[ch-'a']=1;
	}
	return ;
}
inline int Max(const int x,const int y){
	return x>y?x:y;
}
inline int Min(const int x,const int y){
	return x<y?x:y;
}
int ans,las;
inline void Solve(){
	ans=0;
	las=1;
	for(int i=1;i<=n;i++){
		int c=s[i]-'a';
		if(!vis[c]) continue ;
		ans=Max(ans,i-las);
		las=i;
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