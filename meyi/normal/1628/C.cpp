#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=1e3+10;
int n;
bool vis[maxn][maxn];
inline bool check(int x,int y){
	bool ret=0;
	if(x>1)ret^=vis[x-1][y];
	if(y>1)ret^=vis[x][y-1];
	if(y<n)ret^=vis[x][y+1];
	if(x<n)ret^=vis[x+1][y];
	return ret;
}
int a[maxn][maxn],ans,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=n;++j)
				scanf("%d",&a[i][j]),vis[i][j]=false;
		ans=0;
		for(ri i=2;i<=n;++i)
			for(ri j=1;j<=n;++j)
				if(!check(i-1,j))
					ans^=a[i][j],vis[i][j]=true;
		printf("%d\n",ans);
	}
	return 0;
}