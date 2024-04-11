#include<cstdio>
const int N=1e5+5;
int a[N],n,T;
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
int cnt;
inline void Solve(){
	cnt=0;
	n=Read();
	for(int i=1;i<=n;i++){
		a[i]=Read();
		if(a[i]<0){
			cnt++;
			a[i]=-a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt){
			a[i]=-a[i];
			cnt--;
		}
		if(i>1&&a[i]<a[i-1]){
			puts("NO");
			return ;
		}
	}
	puts("YES");
	return ;
}
int main(){
	for(T=Read();T;T--)
		Solve();
	return 0;
}