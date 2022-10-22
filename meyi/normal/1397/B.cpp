#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],n;
inline ll calc(int k){
	ll m=1,ret=0;
	for(ri i=1;i<=n;++i,m*=k){
		ret+=abs(a[i]-m);
		if(m>=LLONG_MAX/k)return LLONG_MAX;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	sort(a+1,a+n+1);
	ri k=pow(a[n],1.0/(n-1));
	printf("%lld",min(calc(k),calc(k+1)));
	return 0;
}