#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int to,nxt;
}e[maxn<<1];
int deg[maxn],hd[maxn],len;
inline void addedge(int fr,int to){
	++deg[to];
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int clr[maxn];
vector<int>g[maxn];
void dfs(int p,bool t){
	for(ri i:g[p]){
		if(clr[i]==-1)clr[i]=t,dfs(i,!t);
		else if(clr[p]==clr[i])puts("NO"),exit(0);
	}
}
int cnt,id[maxn],m,n,op[maxn],x[maxn],y[maxn];
inline void toposort(){
	queue<int>q;
	for(ri i=1;i<=n;++i)
		if(!deg[i])
			q.push(i);
	while(q.size()){
		ri p=q.front();q.pop();
		id[p]=++cnt;
		for(ri i:g[p])
			if(!--deg[i])
				q.push(i);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=m;++i)scanf("%d%d%d",op+i,x+i,y+i),g[x[i]].push_back(y[i]),g[y[i]].push_back(x[i]);
	clear(clr,n,-1);
	for(ri i=1;i<=n;++i)
		if(clr[i]==-1)
			dfs(i,0);
	for(ri i=1;i<=m;++i){
		if((op[i]&1)^clr[x[i]])addedge(x[i],y[i]);
		else addedge(y[i],x[i]);
	}
	toposort();
	if(cnt!=n)puts("NO");
	else{
		puts("YES");
		for(ri i=1;i<=n;++i)printf("%c %d\n",clr[i]?'R':'L',id[i]);
	}
	return 0;
}