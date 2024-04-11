#include<cstdio>
const int N=4e4+5;
const int M=505;
const int Mod=1e9+7;
int f[N][M],g[N][M],T,n;
int p[N],cnt;
char s[N];
int len;
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
inline bool Check(int x){
	len=0;
	while(x){
		s[++len]=x%10+48;
		x/=10;
	}
	for(int i=1;i<=len;i++)
		if(s[i]!=s[len-i+1]) return 0;
	return 1;
}
inline void Init(){
	for(int i=1;i<=N-5;i++)
		if(Check(i)) p[++cnt]=i;
	f[0][0]=1;
	for(int i=0;i<=cnt;i++)
		g[0][i]=1;
	for(int i=1;i<=N-5;i++){
		for(int j=1;j<=cnt&&p[j]<=i;j++)
			f[i][j]=g[i-p[j]][j];
		for(int j=1;j<=cnt;j++)
			g[i][j]=(g[i][j-1]+f[i][j])%Mod;
	}
	return ;
}
int main(){
	Init();
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);
		Print(g[n][cnt]);
	}
	return 0;
}