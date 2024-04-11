#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
ll ans[maxn],mn,sum;
int dep[maxn],siz[maxn];
bool vis[maxn];
void dfs(int p,int f,bool t){
	dep[p]=dep[f]+1;
	if(t){if(siz[p]==1&&vis[p])ckmin(mn,ans[p]+dep[p]-1);}
	else siz[p]=vis[p];
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs(e[i].to,p,t);
			if(!t&&siz[e[i].to])sum+=2,siz[p]+=siz[e[i].to];
		}
}
int a[maxn],k,n,t_case,x,y;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d%d",&n,&k,&x,&y);
		clear(vis,n);
		for(ri i=1;i<=k;++i)scanf("%d",a+i),vis[a[i]]=1;
		clear(hd,n),len=0;
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		mn=LLONG_MAX,sum=0;
		dfs(x,0,0);
		for(ri i=1;i<=k;++i)ans[a[i]]=sum-dep[a[i]]+1;
		dfs(y,0,1);
		printf("%lld\n",mn);
	}
	return 0;
}