#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
ll a;
int t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld",&a);
		ll ans=0;
		for(ri i=0;i<61;++i)ans+=(a>>i);
		printf("%lld\n",ans);
	}
	return 0;
}