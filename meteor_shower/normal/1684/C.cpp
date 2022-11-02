#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int a[N],b[N],n,m,T;
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
inline int Get(const int x,const int y){
	return (x-1)*m+y;
}
inline void Init(){
	n=Read();m=Read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			b[Get(i,j)]=a[Get(i,j)]=Read();
	return ;
}
inline void Swap(int&x,int&y){
	int tmp=x;
	x=y;y=tmp;
	return ;
}
inline void Turn(const int i,const int j){
	for(int k=1;k<=n;k++)
		Swap(a[Get(k,i)],a[Get(k,j)]);
	return ;
}
int ansj,ansk;
inline void Get(){
	ansj=ansk=1;
	for(int i=1;i<=n;i++){
		sort(b+Get(i,1),b+Get(i,m)+1);
		int jj=0,kk=0;
		for(int j=1;j<=m;j++)
			if(a[Get(i,j)]!=b[Get(i,j)]){
				if(!jj) jj=j;
				else kk=j;
			}
		if(jj&&kk){
			ansj=jj;
			ansk=kk;
			return Turn(jj,kk);
		}
	}
	return ;
}
inline bool Check(){
	for(int i=1;i<=n;i++)
		for(int j=2;j<=m;j++)
			if(a[Get(i,j)]<a[Get(i,j-1)]) return 0;
	return 1;
}
inline void Solve(){
	Get();
	if(Check()){
		Print(ansj,' ');
		Print(ansk);
	}
	else puts("-1");
	return ;
}
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}