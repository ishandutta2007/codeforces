#include<cstdio>
typedef long long LL;
const int N=30;
int a[N],b[N];
int n;
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
inline void print(const LL x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(const LL x,const char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline void Swap(int&x,int&y){
	int tmp=x;
	x=y;y=tmp;
	return ;
}
inline void Init(){
	n=Read();
	for(register int i=1;i<=n;i++)
		a[i]=Read();
	for(register int i=1;i<=n;i++){
		b[i]=Read();
		if(a[i]>b[i]) Swap(a[i],b[i]);
	}
	return ;
}
inline int Abs(const int x){
	return x>0?x:-x;
}
LL ans;
inline void Solve(){
	ans=0;
	for(register int i=1;i<n;i++)
		ans+=Abs(a[i+1]-a[i])+Abs(b[i+1]-b[i]);
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