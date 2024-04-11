#include<cstdio>
const int N=1e6+5;
const int Mod=1e9+7;
int n,f[N],pw[N];
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
inline int Quick_Pow(int a,int b){
	int ss=1;
	for(;b;b>>=1){
		if(b&1) ss=1ll*ss*a%Mod;
		a=1ll*a*a%Mod;
	}
	return ss;
}
inline void Init(){
	n=Read();
	for(int i=1;i<=n+1;i++)
		f[i]=0;
	pw[0]=1;
	for(int i=1;i<=n;i++)
		pw[i]=2*pw[i-1]%Mod;
	return ;
}
inline int addv(int x,int y){
	int s=x+y;
	if(s>=Mod) s-=Mod;
	return s;
}
inline int subv(int x,int y){
	int s=x-y;
	if(s<0) s+=Mod;
	return s;
}
inline void add(int&x,int y){
	x=addv(x,y);
	return ;
}
inline void sub(int&x,int y){
	x=subv(x,y);
	return ;
}
int ss;
inline void Solve(){
	f[n]=2;
	f[n-1]=Mod-2;
	for(int i=n;i;i--){
		add(f[i],f[i+1]);
		int j=i/2+1;
		//printf("i=%d f=%d j=%d\n",i,f[i],j);
		add(f[i-1],f[i]);
		sub(f[j-1],f[i]);
	}
	ss=0;
	for(int i=1;i<=n;i++)
		Print(1ll*pw[i/2]*f[i]%Mod*Quick_Pow(pw[n],Mod-2)%Mod);
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