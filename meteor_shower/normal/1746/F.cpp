#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;
typedef long long LL;
const int N=3e5+5;
const int M=35;
const int Mod=1e9+7;
int n,q;
int a[N];
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
inline int Lowbit(int x){
	return x&(-x);
}
struct BIT{
	LL c[N];
	inline void Change(int x,int value){
		for(int i=x;i<=n;i+=Lowbit(i))
			c[i]+=value;
		return ;
	}
	inline LL Query(int x){
		LL ss=0;
		for(int i=x;i;i-=Lowbit(i))
			ss+=c[i];
		return ss;
	}
}bit[M];
/*inline void New(int x,){
	for(int i=0;i<M;i++)
		hsh[i][x]=1ll*rand()*rand()%Mod;
	return ;
}*/
inline int Nxt(int x){
	unsigned long long s=x;
	s^=(s<<20);
	s^=(s>>10);
	s^=(s<<15);
	return s%Mod;
}
inline void Upd(int p,int x){
	//if(hsh[0].find(x)==hsh[0].end()) New(x);
	int s1=a[p],s2=x;
	for(int i=0;i<M;i++){
		bit[i].Change(p,s2-s1);
		s1=Nxt(s1);
		s2=Nxt(s2);
	}
	a[p]=x;
	return ;
}
inline void Init(){
	n=Read(),q=Read();
	for(int i=1;i<=n;i++){
		int x=Read();
		Upd(i,x);
	}
	return ;
}
inline void Solve(){
	for(;q;q--){
		int opt=Read();
		if(opt==1){
			int i=Read();
			int x=Read();
			Upd(i,x);
		}
		else{
			int ql=Read();
			int qr=Read();
			int k=Read();
			bool flg=1;
			for(int i=0;i<M;i++){
				LL ss=bit[i].Query(qr)-bit[i].Query(ql-1);
				if(ss%k) flg=0;
			}
			if(flg) puts("YES");
			else puts("NO");
		}
	}
	return ;
}
int main(){
	Init();
	Solve();
	return 0;
}