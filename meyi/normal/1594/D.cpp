#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=5e5+10;
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
int a[maxn],m,n,t_case;
char op[10];
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>e;
vector<int>g[maxn];
int ans,cnt1,cnt2,vis[maxn];
void dfs(int p,int k){
	if(cnt1==-1)return;
	cnt1+=d.siz[p];
	if(k==1)cnt2+=d.siz[p];
	vis[p]=k;
	for(auto i:g[p])
		if(!vis[i])dfs(i,-k);
		else if(vis[p]==vis[i]){
			cnt1=-1;
			return;
		}
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		d.init(n);
		e.clear();
		while(m--){
			ri x,y;
			scanf("%d%d%s",&x,&y,op);
			if(*op=='c')d.merge(x,y);
			else e.emplace_back(x,y);
		}
		for(ri i=1;i<=n;++i)g[i].clear(),vis[i]=0;
		for(auto i:e){
			ri x=d.find(i.fi),y=d.find(i.se);
			if(x==y){
				puts("-1");
				goto skip;
			}
			g[x].push_back(y),g[y].push_back(x);
		}
		ans=0;
		for(ri i=1;i<=n;++i)
			if(d.find(i)==i&&!vis[i]){
				cnt1=cnt2=0;
				dfs(i,1);
				if(cnt1==-1){
					puts("-1");
					goto skip;
				}
				ans+=max(cnt2,cnt1-cnt2);
			}
		printf("%d\n",ans);
		skip:;
	}
	return 0;
}