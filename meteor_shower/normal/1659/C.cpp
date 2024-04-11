#include<cstdio>
typedef long long LL;
using namespace std;
const int N=2e5+5;
int xx[N],n,a,b;
LL sum[N];
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
inline void Init(){
	n=Read();a=Read();b=Read();
	for(register int i=1;i<=n;i++){
		xx[i]=Read();
		sum[i]=sum[i-1]+xx[i];
	}
	return ;
}
inline LL Get(const int i,const int j){
	return 1ll*b*(xx[j]-xx[i]);
}
inline LL Min(const LL x,const LL y){
	return x<y?x:y;
}
LL ans;
inline void Solve(){
	int now=0;
	ans=1ll<<60;
	for(register int i=0;i<=n;i++)
		ans=Min(ans,1ll*(a+b)*xx[i]+(sum[n]-sum[i]-1ll*(n-i)*xx[i])*b);
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