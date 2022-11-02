#include<cstdio>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1e5+5;
int n,m;
LL sum[N];
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
	n=Read();m=Read();
	for(int i=1;i<=n;i++){
		sum[i]=0;
		for(int j=1;j<=m;j++){
			LL x=Read();
			sum[i]+=x*(m-j+1);
		}
	}
	return ;
}
inline void Solve(){
	int k=0;
	if(sum[1]<sum[2]) k=1;
	else{
		for(int i=2;i<=n;i++)
			if(sum[i]!=sum[1]) k=i;
	}
	LL ans;
	if(k==1) ans=sum[2]-sum[1];
	else ans=sum[1]-sum[k];
	printf("%d %lld\n",k,ans);
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