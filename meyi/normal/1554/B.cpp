#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],k,m,n,t_case;
inline ll calc(int x,int y){
	return 1ll*x*y-1ll*k*(a[x]|a[y]);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		ll ans=LLONG_MIN;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			for(ri j=max(i-2*k,1);j<i;++j)ckmax(ans,calc(i,j));
		}
		printf("%lld\n",ans);
	}
	return 0;
}