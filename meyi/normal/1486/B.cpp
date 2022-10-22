#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e3+10;
int n,t,x[maxn],y[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d%d",x+i,y+i);
		if(n&1){
			puts("1");
			continue;
		}
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		int p=n>>1;
		printf("%lld\n",1ll*(x[p+1]-x[p]+1)*(y[p+1]-y[p]+1));
	}
	return 0;
}