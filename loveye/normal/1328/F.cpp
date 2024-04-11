#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
int n,k,a[N],s[N],p,q,l,r,cnt,ans = 0xfeeddeadbeef;
signed main() {
	scanf("%lld%lld",&n,&k);
	for(int i = 1;i <= n;++i)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i = 1;i <= n+3;++i)
		s[i] = s[i-1] + a[i];
	for(int i = 1,x;i <= n;++i) {
		p = lower_bound(a+1,a+n+1,a[i]) - a;--p;
		l = (p*(a[i]-1)) - s[p];
		q = upper_bound(a+1,a+n+1,a[i]) - a;
		r = (s[n]-s[q-1]) - ((n-q+1)*(a[i]+1));
		x = q-p-1;
		if(x >= k) return puts("0"),0;
		k -= x;
		if(p >= k) ans = min(ans,l + k);
		if(n-q+1 >= k) ans = min(ans,r + k);
		ans = min(ans,l + r + k);
		k += x;
	}
	printf("%lld\n",ans);
	return 0;
}