#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;
const int N=2e5+5;
int n,q,a[N];
int p[N],cnt;
vector<LL>in[N];
multiset<LL>s;
bool vis[N];
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
inline void print(const LL x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(const LL x,const char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline void Init_Prm(){
	vis[1]=1;
	for(int i=2;i<=N-5;i++)
		for(int j=i+i;j<=N-5;j+=i)
			vis[j]=1;
	return ;
}
inline void Init(){
	n=Read();q=Read();
	cnt=0;
	for(int i=1;i<=n;i++){
		a[i]=Read();
		if(i==n) break ;
		if(n%i==0&&!vis[n/i]){
			p[++cnt]=i;
			in[i].clear();
			for(int j=0;j<i;j++)
				in[i].push_back(0);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=cnt;j++){
			//printf("i=%d p=%d to=%d\n",i,p[j],i%p[j]);
			in[p[j]][i%p[j]]+=a[i];
		}
	s.clear();
	for(int i=1;i<=cnt;i++){
		int val=p[i];
		for(int j=0;j<val;j++){
			//printf("val=%d j=%d in=%d\n",val,j,in[val][j]);
			s.insert(in[val][j]*val);
		}
	}
	return ;
}
inline void Solve(){
	Print(*(--s.end()));
	for(;q;q--){
		int u=Read(),x=Read();
		for(int i=1;i<=cnt;i++){
			int val=p[i];
			s.erase(s.find(in[val][u%val]*val));
			in[val][u%val]+=x-a[u];
			s.insert(in[val][u%val]*val);
		}
		a[u]=x;
		Print(*(--s.end()));
	}
	return ;
}
int T;
int main(){
	Init_Prm();
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}