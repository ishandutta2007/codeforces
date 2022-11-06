#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int cas; scanf("%d",&cas);
	while (cas--){
		ll n; scanf("%lld",&n);
		ll l=0,r=n-1,mid;
		while (l<r){
			mid=l+r>>1;
			if (mid>=(n-mid)*(n-mid-1)/2) r=mid; else l=mid+1;
		}
		printf("%lld\n",max(2*(l-1),l+(n-l)*(n-l-1)/2));
	}
	return 0;
}