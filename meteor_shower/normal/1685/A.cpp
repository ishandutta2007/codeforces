#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int ans[N],n,a[N];
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
	for(int i=1;i<=n;i++)
		a[i]=Read();
	return ;
}
inline bool Check(){
	for(int i=1;i<=n;i++){
		int pre=i-1;
		int suf=i%n+1;
		if(pre==0) pre=n;
		if(ans[i]>ans[pre]&&ans[i]>ans[suf]) continue ;
		if(ans[i]<ans[pre]&&ans[i]<ans[suf]) continue ;
		return 0;
	}
	return 1;
}
inline void Solve(){
	sort(a+1,a+n+1);
	int j=0;
	for(int i=1;i<=n;i+=2)
		ans[i]=a[++j];
	for(int i=2;i<=n;i+=2)
		ans[i]=a[++j];
	if(Check()){
		puts("YES");
		for(int i=1;i<=n;i++)
			Print(ans[i],' ');
		putchar('\n');
		return ;
	}
	j=n;
	for(int i=1;i<=n;i+=2)
		ans[i]=a[j--];
	for(int i=2;i<=n;i+=2)
		ans[i]=a[j--];
	if(Check()){
		puts("YES");
		for(int i=1;i<=n;i++)
			Print(ans[i],' ');
		putchar('\n');
		return ;
	}
	puts("NO");
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