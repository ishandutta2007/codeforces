#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=60;
int a,b,n,t;
ll ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&b);
		ans=0;
		while(--n){
			scanf("%d",&a);
			int tmp=ceil(log2(1.0*max(a,b)/min(a,b)))-1;
			if(tmp>0)ans+=tmp;
			b=a;
		}
		printf("%lld\n",ans);
	}
	return 0;
}