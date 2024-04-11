#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n;ll l0,l1,r0,r1,ans,a[N],b[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
		l0=l1=r0=r1=1e18;
		for(int i=1;i<=n;i++)l0=min(l0,abs(a[1]-b[i])),l1=min(l1,abs(b[1]-a[i])),r0=min(r0,abs(a[n]-b[i])),r1=min(r1,abs(b[n]-a[i]));
		printf("%lld\n",min(min(min(l0+l1+r0+r1,abs(a[1]-b[1])+abs(a[n]-b[n])),abs(a[1]-b[n])+abs(a[n]-b[1])),min(min(l0+l1+abs(a[n]-b[n]),r0+r1+abs(a[1]-b[1])),min(l0+r1+abs(a[n]-b[1]),l1+r0+abs(a[1]-b[n])))));
	}
	return 0;
}