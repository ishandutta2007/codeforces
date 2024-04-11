#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,m,a[N],b[N];
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
	n=Read();
	m=Read();
	for(int i=1;i<=m;i++)
		a[i]=Read();
	sort(a+1,a+m+1);
	for(int i=1;i<m;i++)
		b[i]=a[i+1]-a[i]-1;
	b[m]=n-a[m]+a[1]-1;
	return ;
}
int ans;
inline void Solve(){
	ans=0;
	sort(b+1,b+m+1);
	reverse(b+1,b+m+1);
	for(int i=1;i<=m;i++){
		int t=(i-1)*2;
		int res=b[i]-2*t;
		if(res==1) ans++;
		if(res>0) ans+=res-1;
	}
	ans=n-ans;
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