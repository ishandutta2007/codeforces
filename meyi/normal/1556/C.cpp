#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int a[maxn],n;
ll ans; 
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<=n;++i)
		if(i&1){
			ll cntl=0,cntr=0,mx=0;
			for(ri j=i+1;j<=n;++j){
				if(cntr>a[i]+cntl)break;
				if(j&1)cntl+=a[j];
				else{
					cntr+=a[j];
					ans+=max(min((ll)a[i],max(cntr-cntl,0ll))-mx,0ll);
					ckmax(mx,max(cntr-cntl-1,0ll));
				}
			}
		}
	printf("%lld",ans);
	return 0;
}