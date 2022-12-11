// 
#include<bits/stdc++.h>
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
const int N=4e5+10;
int n,m,k,max,ans,t[N],f[N],g[N];
std::queue<int> q;
std::vector<int> G[N];
inline bool cmp(int x,int y){
	return f[x]<f[y];
}
void bfs(int u,int *dis){
	memset(dis+1,-1,n<<2);
	q.push(u),dis[u]=0;
	while(q.size()){
		int u=q.front(); q.pop();
		for(int v:G[u])if(!~dis[v]){
			dis[v]=dis[u]+1;
			// printf("%d -> %d : %d %d\n",u,v,dis[u],dis[v]);
			q.push(v);
		}
	}
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(m),read(k);
	for(int i=1;i<=k;i++)read(t[i]);
	for(int u,v,i=1;i<=m;i++){
		read(u),read(v);
		G[u].push_back(v),G[v].push_back(u);
	}
	// puts("!");
	bfs(1,f),bfs(n,g);
	std::sort(t+1,t+k+1,cmp);
	// for(int i=1;i<=n;i++)print(f[i]," \n"[i==n]);
	// for(int i=1;i<=n;i++)print(g[i]," \n"[i==n]);
	for(int i=1;i<k;i++){
		int x=t[i],y=t[i+1];
		if(std::abs(f[x]-f[y])<1){
			print(f[n],'\n');
			return 0;
		}
		ans=std::max(ans,std::min(f[x]+g[y]+1,f[y]+g[x]+1));
	}
	print(std::min(ans,f[n]),'\n');
}