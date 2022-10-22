#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1);
		ll ans=0;
		for(ri i=2;i<=n;++i)ans+=1ll*(a[i]-a[i-1])*(i-1)*(n-i+1);
		printf("%lld\n",-(ans-a[n]));
	}
	return 0;
}