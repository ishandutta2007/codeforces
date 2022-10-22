#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=1e5+10,mod=1e9+7;
int a[maxn],ans,b[maxn],m,n,nxt[maxn],t_case;
bool ban[maxn],vis[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		for(ri i=1;i<=n;++i)scanf("%d",b+i),nxt[a[i]]=b[i];
		clear(ban,n);
		for(ri i=1,x;i<=n;++i)scanf("%d",&x),ban[a[i]]=!!x;
		ans=1,clear(vis,n);
		for(ri i=1;i<=n;++i)
			if(nxt[i]!=i&&!vis[i]){
				bool add=false;
				for(ri j=i;!vis[j];j=nxt[j])add|=ban[j],vis[j]=true;
				if(!add)ans=ans*2%mod;
			}
		printf("%d\n",ans);
	}
	return 0;
}