#include<cstdio>
typedef long long LL;
int n,m,k;
LL s1,s2;
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
bool flg1,flg2;
bool ans1,ans2;
inline void Solve(){
	for(k=Read();k;k--){
		int x=Read();
		if(x/n>1){
			if(s1==1) ans1=flg1;
			else s1-=x/n;
			if(x/n>2) flg1=1;
		}
		if(x/m>1){
			if(s2==1) ans2=flg2;
			else s2-=x/m;
			if(x/m>2) flg2=1;
		}
	}
	if(s1<=0||s2<=0||ans1||ans2) puts("Yes");
	else puts("No");
	return ;
}
inline void Init(){
	n=Read(),m=Read();
	s1=m,s2=n;
	flg1=flg2=0;
	ans1=ans2=0;
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