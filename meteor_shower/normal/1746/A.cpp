#include<cstdio>
const int N=55;
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
int n,k,a[N];
bool f[N];
inline void Init(){
	n=Read();
	k=Read();
	for(int i=1;i<=n;i++){
		a[i]=Read();
		f[i]=0;
	}
	return ;
}
inline void Solve(){
	for(int i=1;i<=n;i++)
		if(a[i]==1){
			puts("YES");
			return ;
		}
	puts("NO");
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