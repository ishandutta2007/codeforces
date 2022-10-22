#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=3e5+10;
int f[maxn],m,k,n,pos[maxn],t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		memset(f,0x3f,sizeof f);
		for(ri i=1;i<=k;++i)scanf("%d",pos+i);
		for(ri i=1,x;i<=k;++i){
			scanf("%d",&x);
			f[pos[i]]=x;
		}
		for(ri i=1,best=0;i<=n;++i){
			if(f[i]<f[best]+i-best)best=i;
			ckmin(f[i],f[best]+i-best);
		}
		for(ri i=n,best=n+1;i;--i){
			if(f[i]<f[best]+best-i)best=i;
			ckmin(f[i],f[best]+best-i);
		}
		for(ri i=1;i<=n;++i)printf("%d ",f[i]);
		printf("\n");
	}
	return 0;
}