#include<cstdio>
const int N=2e5+5;
int a[N],n,ans,x;
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
inline int Max(const int x,const int y){
	return x>y?x:y;
}
inline int Min(const int x,const int y){
	return x<y?x:y;
}
inline void Solve(){
	ans=-1;
	for(int ll=1,rr;ll<=n;ll=rr+1){
		ans++;
		int mn=a[ll],mx=a[ll];
		rr=ll;
		while(rr<n&&mn+x>=mx-x){
			rr++;
			mn=Min(mn,a[rr]);
			mx=Max(mx,a[rr]);
		}
		if(mn+x<mx-x) rr--;
	}
	Print(ans);
	return ;
}
inline void Init(){
	n=Read();
	x=Read();
	for(int i=1;i<=n;i++)
		a[i]=Read();
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