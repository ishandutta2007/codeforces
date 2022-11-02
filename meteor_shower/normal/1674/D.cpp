#include<cstdio>
const int N=2e5+5;
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
inline void Swap(int&x,int&y){
	int tmp=x;
	x=y;y=tmp;
	return ;
}
inline void Init(){
	n=Read();
	for(int i=1;i<=n;i++)
		a[i]=Read();
	return ;
}
inline void Solve(){
	for(int i=n-1;i>=1;i-=2)
		if(a[i]>a[i+1]) Swap(a[i],a[i+1]);
	for(int i=1;i<n;i++)
		if(a[i]>a[i+1]){
			puts("NO");
			return ;
		}
	puts("YES");
	return ;
}
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}