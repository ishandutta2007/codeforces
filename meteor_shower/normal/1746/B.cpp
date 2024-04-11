#include<cstdio>
const int N=1e5+5;
int n,a[N];
int pre[N],suf[N];
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
inline void Init(){
	n=Read();
	for(int i=1;i<=n;i++)
		a[i]=Read();
	suf[n+1]=pre[0]=0;
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=n;i;i--)
		suf[i]=suf[i+1]+(a[i]==0);
	return ;
}
inline int Max(int x,int y){
	return x>y?x:y;
}
inline int Min(int x,int y){
	return x<y?x:y;
}
inline void Cmax(int&x,int y){
	if(y>x) x=y;
	return ;
}
inline void Cmin(int&x,int y){
	if(y<x) x=y;
	return ;
}
int ans;
inline void Solve(){
	ans=n;
	for(int i=0;i<=n;i++){
		int pre1=pre[i];
		int suf0=suf[i+1];
		suf0-=pre1;
		Cmax(suf0,0);
		Cmin(ans,pre1+suf0);
	}
	return Print(ans);
}
int T;
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}