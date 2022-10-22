#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int m,n,t_case;
ll a,ans,xm,xs,ym,ys;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%lld%lld",&n,&xm,&ym);
		ans=(xm+ym)*n;
		xs=xm,ys=ym;
		for(ri i=3;i<=n;++i){
			scanf("%lld",&a);
			if(i&1)xm=min(xm,a),xs+=a;
			else ym=min(ym,a),ys+=a;
			ans=min(ans,xs+(n-(i+1)/2)*xm+ys+(n-i/2)*ym);
		}
		printf("%lld\n",ans);
	}
	return 0;
}