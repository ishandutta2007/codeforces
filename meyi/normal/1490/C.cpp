#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e4+10;
int t;
ll x;
inline bool find(ll k){
	if(k==1)return true;
	int l=1,r=1e4;
	while(l<=r){
		int mid=l+r>>1;
		ll tmp=1ll*mid*mid*mid;
		if(k==tmp)return true;
		if(k>tmp)l=mid+1;
		else r=mid-1;
	}
	return false;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&x);
		bool flag=false;
		for(ri j=1;;++j){
			ll tmp=x-1ll*j*j*j;
			if(tmp<0)break;
			if(find(tmp)){
				flag=true;
				break;
			}
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}