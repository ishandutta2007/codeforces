#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e6+10;
struct dsu{
	int fa[maxn],siz[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y,siz[y]+=siz[x];
		}
	}
}d;
int ans[maxn],cnt,lst[maxn],n,ori[maxn],tot;
bool vis[maxn];
int main(){
	scanf("%d",&n);
	d.init(1000000);
	for(ri i=1;i<=500000;++i)lst[i]=ori[i]=i;
	tot=n;
	while(n--){
		ri op,x,y;
		scanf("%d%d",&op,&x);
		if(op&1){
			if(vis[x])vis[x]=false,lst[x]=++tot,ori[tot]=x;
			ans[++cnt]=lst[x];
		}
		else{
			scanf("%d",&y);
			if(x==y)continue;
			if(vis[x])vis[x]=false,lst[x]=++tot,ori[tot]=x;
			if(vis[y])vis[y]=false,lst[y]=++tot,ori[tot]=y;
			d.fa[lst[x]]=lst[y];
			vis[x]=true;
		}
	}
	for(ri i=1;i<=cnt;++i)printf("%d ",ori[d.find(ans[i])]);
	return 0;
}