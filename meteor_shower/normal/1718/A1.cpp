#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,a[N];
int T;
map<int,int>las;
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
int ll[N],rr[N],id[N],cnt;
inline bool Cmp(const int x,const int y){
	return rr[x]<rr[y];
}
inline void Init(){
	n=Read();
	cnt=0;
	las.clear();
	las[0]=0;
	for(int i=1;i<=n;i++){
		a[i]=Read();
		a[i]^=a[i-1];
		if(las.find(a[i])!=las.end()){
			++cnt;
			id[cnt]=cnt;
			rr[cnt]=i,ll[cnt]=las[a[i]]+1;
		}
		las[a[i]]=i;
	}
	sort(id+1,id+cnt+1,Cmp);
	return ;
}
int ans;
inline void Solve(){
	ans=0;
	int nowr=0;
	for(int i=1;i<=cnt;i++)
		if(ll[i]>nowr){
			nowr=rr[i];
			ans++;
		}
	Print(n-ans);
	return ;
}
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}