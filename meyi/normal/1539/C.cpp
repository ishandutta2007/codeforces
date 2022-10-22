#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int ans,m,n,t_case;
ll a[maxn],b[maxn],k,x;
int main(){
	scanf("%d%lld%lld",&n,&k,&x);
	for(ri i=1;i<=n;++i)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(ri i=2;i<=n;++i)b[i]=max((a[i]-a[i-1]-1)/x,0ll);
	sort(b+2,b+n+1);
	ans=n;
	for(ri i=2;i<=n;++i)
		if(b[i]<=k)--ans,k-=b[i];
		else break;
	printf("%d",ans);
	return 0;
}