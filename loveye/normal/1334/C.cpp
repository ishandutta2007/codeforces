#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
#define int long long
int n,a[N],b[N];
signed main() {
	int t;scanf("%lld",&t);
	b[0] = 0xfeeddeadbeef;
	while(t--) {
		int mn = 0,ans = 0;
		scanf("%lld",&n);
		for(int i = 1;i <= n;++i)
			scanf("%lld%lld",a+i,b+i),ans += a[i];
		for(int i = 1;i <= n;++i)
			b[i] = min(b[i],a[i%n+1]),ans -= b[i];
		for(int i = 1;i <= n;++i)
			if(b[i] < b[mn]) mn = i;
		ans += b[mn];
		cout << ans << endl;
	}
	return 0;
}