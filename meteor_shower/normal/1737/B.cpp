#include<cstdio>
#include<cmath>
#define int long long
typedef long long LL;
inline LL Read(){
	char ch;
	int f=1;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	LL x=ch^48;
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
inline int Get(LL x){
	if(x==0) return 0;
	int sqr=sqrt(x);
	//printf("sqr=%d x=%lld\n",sqr,x);
	while(1ll*sqr*sqr<x) sqr++;
	while(1ll*sqr*sqr>x) sqr--;
	//printf("sqr=%d x=%lld\n")
	int ss=0;
	if(sqr>0) ss+=3*(sqr-1);
	LL ll=1ll*sqr*sqr;
	ss+=(x-ll)/sqr;
	ss++;
	return ss;
}
LL ll,rr;
int T;
signed main(){
	for(T=Read();T;T--){
		ll=Read();
		rr=Read();
		Print(Get(rr)-Get(ll-1));
	}
}