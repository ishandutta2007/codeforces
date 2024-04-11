#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=2e5+5;
bool vis[N];
int a[N],n,k,id[N],T;
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
inline bool Cmp(const int x,const int y){
	return -a[x]-x<-a[y]-y;
}
inline void Init(){
	n=Read();
	k=Read();
	for(int i=1;i<=n;i++){
		a[i]=Read();
		id[i]=i;
	}
	sort(id+1,id+n+1,Cmp);
	return ;
}
LL ss;
inline void Solve(){
	ss=0;
	for(int i=1;i<=n;i++)
		ss+=a[i];
	for(int i=1;i<=k;i++)
		ss+=-a[id[i]]+n-id[i]-k;
	for(int i=1;i<=k;i++)
		ss+=i;
	Print(ss);
	return ;
}
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}