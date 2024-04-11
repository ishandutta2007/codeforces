#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+5;
const int block=750;
const int M=750;
int n;
int cnt[2][M];
int num[2][N],m[2];
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
	memset(cnt,0,sizeof(cnt));
	n=Read();
	for(int i=1;i<=n;i++)
		num[0][i]=Read();
	m[0]=n;
	m[1]=0;
	return ;
}
inline void Add(const int p,const int x){
	if(x<block) cnt[p][x]++;
	else num[p][++m[p]]=x;
	return ;
}
inline void Solve(){
	int p=0;
	for(int i=1;i<n;i++){
		int las=-1;
		for(int j=0;j<block;j++){
			if(!cnt[p][j]) continue ;
			cnt[p^1][0]+=cnt[p][j]-1;
			if(las!=-1) Add(p^1,j-las);
			las=j;
			cnt[p][j]=0;
		}
		for(int j=1;j<=m[p];j++){
			int x=num[p][j];
			if(las!=-1) Add(p^1,x-las);
			las=x;
		}
		m[p]=0;
		p^=1;
	}
	for(int i=0;i<block;i++)
		if(cnt[p][i]) Print(i);
	if(m[p]) Print(num[p][1]);
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