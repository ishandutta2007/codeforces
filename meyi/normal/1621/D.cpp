#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=510;
int a[maxn][maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		int mn=INT_MAX;
		ll sum=0;
		for(ri i=1;i<=n*2;++i)
			for(ri j=1;j<=n*2;++j){
				scanf("%d",&a[i][j]);
				if(i>n&&j>n)sum+=a[i][j];
			}
		printf("%lld\n",sum+min({a[n+1][1],a[n+1][n],a[n*2][1],a[n*2][n],a[1][n+1],a[1][n*2],a[n][n+1],a[n][n*2]}));
	}
	return 0;
}