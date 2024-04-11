#include <bits/stdc++.h>
#define ll long long

ll ans,res;
int n,arr[300005];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&arr[i]);
	for (int i=1;i<=n;++i) {
		ll d=std::min((ll)arr[i]/2,res);
		arr[i]-=d*2;res-=d; ans+=d;
		if (arr[i]>0)	{ ans+=arr[i]/3; res+=arr[i]-arr[i]/3*3;}
	}std::cout<<ans;
	return 0;
}