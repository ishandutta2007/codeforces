#include<cstdio>
#define int long long
const int N=3e5+5;
int n,h[N],mx,nd2,nd1;
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
inline void Init(){
	n=Read();
	mx=0;
	for(register int i=1;i<=n;i++){
		h[i]=Read();
		mx=Max(mx,h[i]);
	}
	return ;
}
inline int Get(){
	nd2=nd1=0;
	for(register int i=1;i<=n;i++){
		int rest=mx-h[i];
		nd2+=rest/2;
		nd1+=rest%2;
	}
	if(nd2>nd1){
		int x=(nd2-nd1)/3;
		nd2-=x,nd1+=x*2;
		if(nd2==nd1+2) nd2--,nd1+=2;
	}
	//Print(nd2,' ');
	//Print(nd1);
	if(nd2>=nd1) return nd2*2;
	return nd1*2-1;
}
int ans;
inline void Solve(){
	ans=1ll<<60;
	ans=Min(ans,Get());
	mx++;
	ans=Min(ans,Get());
	Print(ans);
	return ;
}
int T;
signed main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}