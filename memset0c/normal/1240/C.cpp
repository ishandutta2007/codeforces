#include<bits/stdc++.h>
#define ll long long
// #define int long long
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=5e5+10;
int T,n,k;
ll f[N][2];
std::vector<std::pair<int,int>> G[N];
void dfs(int u,int fa){
	std::vector<ll> p;
	for(auto it:G[u])if(it.first!=fa){
		int v=it.first,w=it.second;
		dfs(v,u);
		// printf("%d -> %d : %d | %d %d\n",u,v,w,f[v][0],f[v][1]);
		f[u][0]+=f[v][0],f[u][1]+=f[v][0],p.push_back(f[v][1]-f[v][0]+w);
	}
	// printf(">> F %d : %d %d\n",u,f[u][0],f[u][1]);
	std::sort(p.begin(),p.end()),std::reverse(p.begin(),p.end());
	for(int i=0;i<p.size()&&i<k-1;i++)if(p[i]>0)f[u][0]+=p[i],f[u][1]+=p[i]; else break;
	if(p.size()>=k&&p[k-1]>0)f[u][0]+=p[k-1];
}
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		read(n),read(k);
		for(int i=1;i<=n;i++)G[i].clear(),f[i][0]=f[i][1]=0;
		for(int u,v,w,i=1;i<n;i++){
			read(u),read(v),read(w);
			G[u].push_back(std::make_pair(v,w));
			G[v].push_back(std::make_pair(u,w));
		}
		dfs(1,0),print(f[1][0],'\n');
		// for(int i=1;i<=n;i++)print(f[i][0]," \n"[i==n]);
		// for(int i=1;i<=n;i++)print(f[i][1]," \n"[i==n]);
	}
}