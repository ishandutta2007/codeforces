#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v=1){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int dep[maxn],id[maxn],k,n,siz[maxn];
void dfs(int p,int f){
	dep[p]=dep[f]+1;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs(e[i].to,p);
			siz[p]+=siz[e[i].to];
		}
}
int main(){
	scanf("%d%d",&n,&k);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
		id[i]=i;
	}
	id[n]=n;
	dfs(1,0);
	sort(id+1,id+n+1,[&](int x,int y){return dep[x]-siz[x]>dep[y]-siz[y];});
	ll ans=0;
	for(ri ii=1;ii<=k;++ii){
		ri i=id[ii];
		ans+=dep[i]-siz[i];
	}
	printf("%lld",ans);
	return 0;
}