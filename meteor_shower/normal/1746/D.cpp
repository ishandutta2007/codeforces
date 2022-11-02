#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long LL;
const int N=2e5+5;
int n;
vector<int>son[N];
map<int,LL>f[N];
multiset<LL>s;
int a[N];
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
inline void print(LL x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(LL x,char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline void Dfs(int u,int k){
	//printf("u=%d k=%d\n",u,k);
	if(f[u].find(k)!=f[u].end()) return ;
	int siz=son[u].size();
	f[u][k]=1ll*k*a[u];
	if(!siz) return ;
	int to=k/siz,rest=k%siz;
	for(int i=0;i<siz;i++){
		int v=son[u][i];
		Dfs(v,to);
		if(rest) Dfs(v,to+1);
	}
	f[u][k]=1ll*k*a[u];
	s.clear();
	for(int i=0;i<siz;i++){
		int v=son[u][i];
		f[u][k]+=f[v][to];
		if(rest) s.insert(f[v][to+1]-f[v][to]);
	}
	for(int i=1;i<=rest;i++){
		multiset<LL>::iterator it=--s.end();
		f[u][k]+=*it;
		s.erase(it);
	}
	return ;
}
int k;
inline void Init(){
	n=Read(),k=Read();
	for(int i=1;i<=n;i++){
		son[i].clear();
		f[i].clear();
	}
	for(int i=2;i<=n;i++){
		int fa=Read();
		son[fa].push_back(i);
	}
	for(int i=1;i<=n;i++)
		a[i]=Read();
	return ;
}
inline void Solve(){
	Dfs(1,k);
	return Print(f[1][k]);
}
int T;
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}