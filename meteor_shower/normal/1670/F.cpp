#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<cstdio>
#include<cstring>
typedef long long LL;
const int N=1005;
const int M=65;
const int Z=2;
const int Mod=1e9+7;
int inv[N],fac[N];
inline int C(const int m,const int n){
	return 1ll*fac[m]*inv[n]%Mod*inv[m-n]%Mod;
}
int f[M][N<<1][Z],n;
LL ll,rr,z;
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
inline int Quick_Pow(int a,int b){
	int ss=1;
	for(;b;b>>=1){
		if(b&1) ss=1ll*ss*a%Mod;
		a=1ll*a*a%Mod;
	}
	return ss;
}
int ccc[N];
inline void Init(){
	n=Read();
	ll=Read();
	rr=Read();
	z=Read();
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
		inv[i]=Quick_Pow(fac[i],Mod-2);
	}
	for(int i=0;i<=n;i++)
		ccc[i]=C(n,i);
	return ;
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
inline int Get(const LL p){
	memset(f,0,sizeof(f));
	f[0][0][1]=1;
	for(int i=1;i<=61;i++){
		bool zi=(z&(1ll<<i-1));
		bool pi=(p&(1ll<<i-1));
		for(int j=0;j<=n;j++){
			if(!f[i-1][j][0]&&!f[i-1][j][1]) continue ;
			for(int k=0;k<=n;k++){
				if(k%2!=zi) continue ;
				int now=(j+k)&1;
				int more=(j+k)>>1;
				//printf("i=%d j=%d k=%d now=%d more=%d\n",i,j,k,now,more);
				//getchar();
				if(now!=pi){
					add(f[i][more][now],1ll*f[i-1][j][0]*ccc[k]%Mod);
					add(f[i][more][now],1ll*f[i-1][j][1]*ccc[k]%Mod);
				}
				else{
					add(f[i][more][0],1ll*f[i-1][j][0]*ccc[k]%Mod);
					add(f[i][more][1],1ll*f[i-1][j][1]*ccc[k]%Mod);
				}
			}
		}
	}
	return f[61][0][0];
}
inline void Solve(){
	int ans;
	rr++;
	ans=Get(rr);
	//Print(ans);
	sub(ans,Get(ll));
	Print(ans);
	return ;
}
int main(){
	Init();
	Solve();
	return 0;
}