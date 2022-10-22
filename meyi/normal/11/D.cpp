#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=19;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
ll ans,f[1<<maxn][maxn];
int e[maxn][maxn],m,n;
signed main(){
	scanf("%d%d",&n,&m);
	ans=-m;
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		--x,--y;
		++e[x][y],++e[y][x];
	}
	for(ri i=0;i<n;++i)f[1<<i][i]=1;
	for(ri i=1;i<1<<n;++i)
		for(ri j=0;j<n;++j)
			if(f[i][j]){
				ri lb=__lg(i&-i);
				ans+=f[i][j]*e[j][lb];
				for(ri k=lb+1;k<n;++k)
					if(!(i&(1<<k))&&e[j][k])
						f[i|(1<<k)][k]+=f[i][j]*e[j][k];
			}
	printf("%lld",ans>>1);
	return 0;
}