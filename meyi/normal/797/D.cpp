#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int ans,ls[maxn],n,rs[maxn],val[maxn];
unordered_map<int,int>cnt;
void dfs(int p,int l,int r){
	if(l<=val[p]&&val[p]<=r)cnt[val[p]]=-114514;
	else ++cnt[val[p]];
	if(~ls[p])dfs(ls[p],l,min(r,val[p]-1));
	if(~rs[p])dfs(rs[p],max(l,val[p]+1),r);
}
bool vis[maxn];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d%d%d",val+i,ls+i,rs+i),vis[max(ls[i],0)]=vis[max(rs[i],0)]=true;
	for(ri i=1;i<=n;++i)
		if(!vis[i])
			dfs(i,0,(int)1e9);
	for(const auto &i:cnt)ans+=max(i.second,0);
	printf("%d",ans);
	return 0;
}