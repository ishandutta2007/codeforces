#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1054321;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
vector<int>g[maxn];
int n,u[maxn],v[maxn];
bool vis[maxn];
int calcsiz(int p){
	vis[p]=true;
	ri ret=1;
	for(auto i:g[p])
		if(!vis[i])
			ret+=calcsiz(i);
	return ret;
}
inline bool check(int k){
	ri bitmask=(1<<k)-1;
	for(ri i=0;i<=bitmask;++i)g[i].clear(),vis[i]=false;
	for(ri i=1;i<=n;++i){
		ri x=u[i]&bitmask,y=v[i]&bitmask;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	ri cnt=0;
	for(ri i=0;i<=bitmask;++i)
		if(g[i].size()&1)return false;
		else if(g[i].size())++cnt;
	for(ri i=0;i<=bitmask;++i)
		if(g[i].size())
			return calcsiz(i)==cnt;
}
typedef pair<int,int> pii;
#define fi first
#define se second
struct edge{
	pii v;
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len=1;
inline void addedge(int fr,int to,pii v){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
	vis[len>>1]=false;
}
vector<pii>ans;
void dfs(int p){
	for(ri i=hd[p];i;i=hd[p]){
		hd[p]=e[i].nxt;
		if(!vis[i>>1]){
			vis[i>>1]=true;
			dfs(e[i].to);
			ans.emplace_back(e[i^1].v);
		}
	}
}
inline void output(int k){
	ri bitmask=(1<<k)-1;
	for(ri i=1;i<=n;++i){
		ri x=u[i]&bitmask,y=v[i]&bitmask;
		addedge(x,y,{(i<<1)-1,i<<1});
		addedge(y,x,{i<<1,(i<<1)-1});
	}
	for(ri i=0;i<=bitmask;++i)
		if(hd[i]){
			dfs(i);
			break;
		}
	printf("%d\n",k);
	for(auto i:ans)printf("%d %d ",i.fi,i.se);
}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d%d",u+i,v+i);
	for(ri i=20;~i;--i)
		if(check(i)){
			output(i);
			break;
		}
	return 0;
}