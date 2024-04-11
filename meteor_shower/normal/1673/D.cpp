#include<cstdio>
const int Mod=1e9+7;
typedef long long LL;
struct Node{
	LL st,en;
	int sub;
}b,c;
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
	b.st=Read();
	b.sub=Read();
	int s=Read();
	b.en=b.st+1ll*b.sub*(s-1);
	c.st=Read();
	c.sub=Read();
	s=Read();
	c.en=c.st+1ll*c.sub*(s-1);
	return ;
}
inline int Gcd(const int x,const int y){
	return !y?x:Gcd(y,x%y);
}
int ans;
inline int Calc(const int suba){
	if(Gcd(c.sub/suba,c.sub/b.sub)!=1) return 0;
	return 1ll*c.sub/suba*c.sub/suba%Mod;
}
inline void add(int&x,const int y){
	x+=y;
	if(x>=Mod) x-=Mod;
	return ;
}
inline void sub(int&x,const int y){
	x-=y;
	if(x<0) x+=Mod;
	return ;
}
inline void Solve(){
	//printf("%lld %d %lld %lld %d %lld\n",b.st,b.sub,b.en,c.st,c.sub,c.)
	ans=0;
	if(c.sub%b.sub){
		puts("0");
		return ;
	}
	if((c.st%b.sub+b.sub)%b.sub!=(b.st%b.sub+b.sub)%b.sub){
		puts("0");
		return ;
	}
	if(b.st>c.st||b.en<c.en){
		puts("0");
		return ;
	}
	if(b.st>c.st-c.sub){
		puts("-1");
		return ;
	}
	if(b.en<c.en+c.sub){
		puts("-1");
		return ;
	}
	for(int i=1;i*i<=c.sub;i++){
		if(c.sub%i) continue ;
		add(ans,Calc(i));
		if(i*i!=c.sub) add(ans,Calc(c.sub/i));
		//printf("i=%d calc=%d\n",i,Calc(i));
		//printf("i=%d calc=%d\n",c.sub/i,Calc(c.sub/i));
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