#include<cstdio>
const int N=2e5+5;
int n,k;
char s[N];
int ans[N];
int f[N];
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
	n=Read();k=Read();
	scanf("%s",s+1);
	for(register int i=1;i<=n;i++)
		f[i]=-1;
	return ;
}
inline void Solve(){
	if(k==0){
		puts(s+1);
		for(register int i=1;i<=n;i++)
			Print(0,' ');
		putchar('\n');
		return ;
	}
	int p=k%2;
	for(register int i=1;i<n;i++){
		if(!k) f[i]=0;
		else{
			f[i]=(s[i]-'0'==p);
			k-=f[i];
		}
		putchar((s[i]-'0'+f[i]+p)%2+48);
	}
	Print((s[n]-'0'+k+p)%2);
	for(register int i=1;i<n;i++)
		Print(f[i],' ');
	Print(k);
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