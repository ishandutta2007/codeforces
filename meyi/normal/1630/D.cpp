#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e6+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri g=0;
		while(m--){
			ri x;
			scanf("%d",&x);
			g=__gcd(g,x);
		}
		ll ans=0,sum0=0,sum1=0;
		for(ri i=1;i<=g;++i){
			bool flag=false;
			ri mn=INT_MAX;
			for(ri j=i;j<=n;j+=g){
				if(a[j]<0)flag^=1;
				ans+=abs(a[j]),ckmin(mn,abs(a[j]));
			}
			(flag?sum0:sum1)+=mn;
		}
		printf("%lld\n",ans-min(sum0,sum1)*2);
	}
	return 0;
}