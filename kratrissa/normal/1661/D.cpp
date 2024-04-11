#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,k;ll w,a[N],ans,d[N];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	ll ts=0,tc=0;
	for(int i=n;i>k;i--){
		ts-=tc,a[i]-=ts,tc-=d[i];
		if(a[i]<=0)continue;
		ans+=(a[i]-1)/k+1,ts+=((a[i]-1)/k+1)*k,tc+=(a[i]-1)/k+1,d[i-k]+=(a[i]-1)/k+1;
	}
	for(int i=k;i>=1;i--)ts-=tc,a[i]-=ts,tc-=d[i];
	for(int i=1;i<=k;i++)if(a[i]>0)w=max(w,(a[i]-1)/i+1);
	printf("%lld\n",ans+w);
	return 0;
}