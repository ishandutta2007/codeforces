#include<cstdio>
#include<algorithm>
const int N=1e5+5;
int n,q;
int a[N],now;
bool ans[N];
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
	q=Read();
	for(int i=1;i<=n;i++){
		a[i]=Read();
		ans[i]=0;
	}
	return ;
}
inline void Solve(){
	now=0;
	for(int i=n;i;i--)
		if(now>=a[i]) ans[i]=1;
		else if(now<q){
			now++;
			ans[i]=1;
		}
	for(int i=1;i<=n;i++)
		putchar(ans[i]+'0');
	putchar('\n');
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