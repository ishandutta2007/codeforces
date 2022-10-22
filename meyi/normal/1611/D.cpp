#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a,ans[maxn],dep[maxn],fa[maxn],m,n,t_case;
bool vis[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",fa+i),ans[i]=-1,dep[i]=0;
		bool flag=false;
		for(ri i=1,pre=0;i<=n;++i){
			scanf("%d",&a);
			if(fa[a]!=a){
				if(ans[fa[a]]==-1)flag=true;
				ans[a]=dep[pre]-dep[fa[a]]+1;
				dep[a]=dep[fa[a]]+ans[a];
			}
			else ans[a]=0;
			pre=a;
		}
		if(flag)puts("-1");
		else{
			for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
			printf("\n");
		}	
	}
	return 0;
}