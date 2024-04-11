#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
int n,t;
ll pl,pos[maxn],pr;
bool flag;
inline int calc(ll k){
	ri p=lower_bound(pos+1,pos+n,k)-pos;
	if((pos[p]-k)&1)return p;
	return p+((k-pos[p-1])>>1);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld%lld",&n,&pl,&pr);
		if(flag=(1ll*n*(n-1)+1==pr)){
			if(pl==pr){
				puts("1");
				continue;
			}
			--pr;
		}
		for(ri i=1;i<n;++i)pos[i]=pos[i-1]+((n-i)<<1);
		for(ll i=pl;i<=pr;++i)printf("%d ",calc(i));
		if(flag)printf("1");
		printf("\n");
	}
	return 0;
}