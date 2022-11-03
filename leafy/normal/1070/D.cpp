#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n,k;
long long ans=0;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
	    scanf("%d",&a[i]);
	    a[i]-=min(a[i],k*(a[i-1]%k!=0)-a[i-1]%k);
	    ans+=(a[i]+k-1)/k;
	}
	printf("%lld",ans);
	return 0;
}