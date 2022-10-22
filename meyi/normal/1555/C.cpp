#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],m,n,prea[maxn],preb[maxn],t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),prea[i]=prea[i-1]+a[i];
		for(ri i=1;i<=n;++i)scanf("%d",b+i),preb[i]=preb[i-1]+b[i];
		ri ans=INT_MAX;
		for(ri i=1;i<=n;++i)ckmin(ans,max(prea[n]-prea[i],preb[i-1]));
		printf("%d\n",ans);
	}
	return 0;
}