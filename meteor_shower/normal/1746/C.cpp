#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
typedef pair<int,int> pr;
const int N=1e5+5;
int n;
int a[N];
set<pr>s;
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
inline void print(int x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(int x,char ch='\n'){
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
	s.clear();
	for(int i=2;i<=n;i++)
		if(a[i-1]>a[i]) s.insert(make_pair(a[i-1]-a[i],i));
	return ;
}
inline void Solve(){
	for(int i=1;i<=n;i++){
		set<pr>::iterator it=s.upper_bound(make_pair(i,n));
		if(it==s.begin()) Print(1,' ');
		else{
			--it;
			Print((*it).second,' ');
			s.erase(it);
		}
	}
	putchar('\n');
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