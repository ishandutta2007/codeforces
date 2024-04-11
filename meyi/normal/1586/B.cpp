#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],b[maxn],c[maxn],m,n,t_case;
bool vis[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)vis[i]=false;
		for(ri i=1;i<=m;++i)scanf("%d%d%d",a+i,b+i,c+i),vis[b[i]]=true;
		for(ri i=1;i<=n;++i)
			if(!vis[i]){
				for(ri j=1;j<=n;++j)
					if(i!=j)
						printf("%d %d\n",i,j);
				break;
			}
	}
	return 0;
}