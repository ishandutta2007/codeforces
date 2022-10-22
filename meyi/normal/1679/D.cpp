#include<bits/stdc++.h>
using namespace std;
#define ri int
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
bool vis[maxn];
bool dfs(int p,ll d){
	if(!--d)return true;
	vis[p]=true;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(vis[e[i].to]||dfs(e[i].to,d))
			return true;
	return false;
}
int cnt,dfn[maxn],low[maxn],st[maxn],tp;
bool flag;
void tarjan(int p){
    dfn[p]=low[p]=++cnt;
    st[++tp]=p,vis[p]=true;
    for(ri i=hd[p];i;i=e[i].nxt){
        if(!dfn[e[i].to])tarjan(e[i].to),ckmin(low[p],low[e[i].to]);
        else if(vis[e[i].to])ckmin(low[p],dfn[e[i].to]);
    }
    if(dfn[p]==low[p]){
        ri k,siz=0;
        do{
            k=st[tp--];
            ++siz;
            vis[k]=false;
        }while(k!=p);
        if(siz>1)flag=true;
    }
}
int a[maxn],f[maxn],m,n,x[maxn],y[maxn];
ll d;
inline bool check(int k){
	clear(deg,n),clear(hd,n),len=0;
	for(ri i=1;i<=m;++i)
		if(a[x[i]]<=k&&a[y[i]]<=k)
			addedge(x[i],y[i]);
	cnt=flag=0,clear(dfn,n);
	for(ri i=1;i<=n;++i)
		if(a[i]<=k&&!dfn[i]){
			tarjan(i);
			if(flag)return true;
		}
	clear(f,n);
	queue<int>q;
	for(ri i=1;i<=n;++i){
		if(a[i]<=k&&!deg[i])f[i]=1,q.push(i);
		else f[i]=0;
	}
	while(q.size()){
		ri p=q.front();q.pop();
		if(f[p]>=d)return true;
		for(ri i=hd[p];i;i=e[i].nxt){
			ckmax(f[e[i].to],f[p]+1);
			if(!--deg[e[i].to])q.push(e[i].to);
		}
	}
	return false;
}
int main(){
	scanf("%d%d%lld",&n,&m,&d);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<=m;++i)scanf("%d%d",x+i,y+i);
	ri ans=INT_MAX,l=1,r=1e9;
	while(l<=r){
		ri mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans==INT_MAX?-1:ans);
	return 0;
}