#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=110;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
bool a[maxn][maxn];
int ans1[maxn],ans2[maxn],d[maxn][maxn],k,m,n,u[maxn][maxn];
signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
			u[i+1][j]=u[i][j]+a[i][j];
		}
	for(ri i=n;i;--i)
		for(ri j=m;j;--j){
			d[i][j]=d[i+1][j]+a[i][j];
			if(a[i][j]){
				ri x=d[i][j]-d[min(i+k,n+1)][j];
				if(ckmax(ans1[j],x))ans2[j]=u[i][j];
				else if(x==ans1[j])ckmin(ans2[j],u[i][j]);
			}
		}
	printf("%d %d",accumulate(ans1+1,ans1+m+1,0),accumulate(ans2+1,ans2+m+1,0));
	return 0;
}