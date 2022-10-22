#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2010;
int a[maxn][maxn],n,t_case;
bool vis[maxn][maxn];
char s[maxn][maxn];
int dfs(int x,int y){
	if(vis[x][y])return a[x][y];
	a[x][y]=0,vis[x][y]=true;
	return a[x][y]=dfs(x%n+1,y%n+1)+(s[x][y]^48);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ri tot=0;
		for(ri i=1;i<=n;++i){
			scanf("%s",s[i]+1),clear(vis[i],n);
			for(ri j=1;j<=n;++j)tot+=(s[i][j]^48);
		}
		ri ans=n*n;
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=n;++j){
				ri cnt=dfs(i,j);
				ckmin(ans,n-cnt+tot-cnt);
			}
		printf("%d\n",ans);
	}
	return 0;
}