#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
ll x,y;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%lld%lld",&n,&x,&y);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ll ans=0;
		for(ri i=1,j=0;i<=n;++i){
			ans+=y*(a[i]-a[j]);
			if(x*(a[i]-a[j])-y*(n-i)*a[i]<-y*(n-i)*a[j])ans+=x*(a[i]-a[j]),j=i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}