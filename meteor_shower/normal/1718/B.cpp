#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=105;
typedef pair<int,int> pr;
set<pr>s;
int n,a[N];
int fib[N];
int k;
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
inline void Init_Fib(){
	fib[1]=fib[2]=1;
	for(int i=3;i<=N-5;i++){
		fib[i]=fib[i-1]+fib[i-2];
		if(fib[i]>1000000000) break ;
	}
	return ;
}
inline void Init(){
	n=Read();
	s.clear();
	for(int i=1;i<=n;i++){
		a[i]=Read();
		s.insert(make_pair(a[i],i));
	}
	return ;
}
inline void Solve(){
	LL ss=0,s1=0;
	for(int i=1;i<=n;i++)
		ss+=a[i];
	k=0;
	while(s1<ss){
		++k;
		if(fib[k]==0) break ;
		s1+=fib[k];
	}
	if(s1!=ss){
		puts("No");
		return ;
	}
	int las=-1;
	for(int i=k;i;i--){
		if(!s.size()){
			puts("No");
			return ;
		}
		set<pr>::iterator it=--s.end();
		int u=(*it).second;
		if(a[u]<fib[i]){
			puts("No");
			return ;
		}
		s.erase(it);
		a[u]-=fib[i];
		if(las!=-1) s.insert(make_pair(a[las],las));
		las=u;
	}
	puts("Yes");
	return ;
}
int T;
int main(){
	Init_Fib();
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}