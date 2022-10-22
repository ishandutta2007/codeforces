#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n,a[N],ans,tans;ll m;
ll calc(int l,int x){if(x==0)return 5e18;int t=l/x;return 1ll*t*t*(x-l%x)+1ll*(t+1)*(t+1)*(l%x);}
ll getr(int x,ll slope){
	int l=1,r=x+1;
	while(l<=r){
		int mid=l+r>>1;
		if(calc(x,mid-1)-calc(x,mid)<=slope)r=mid-1;
		else l=mid+1;
	}
	return r;
}
ll check(ll slope){ll tot=0;for(int i=1;i<=n;i++)tot+=calc(a[i],getr(a[i],slope));return tot;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%lld",&m);
	for(int i=n;i;i--)a[i]-=a[i-1];
	ll l=0,r=1e18;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid)>m)r=mid-1;
		else l=mid+1;
	}
	for(int i=1;i<=n;i++)ans+=getr(a[i],l)-1;ans+=(check(l)-m-1)/l+1;
	for(int i=1;i<=n;i++)tans+=getr(a[i],r)-1;
	printf("%d\n",min(ans,tans));
	return 0;
}