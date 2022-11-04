#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,cnt[2];

signed main() {
	scanf("%lld",&n);
	for(int i=1,m;i<=n;i++)
		scanf("%lld",&m),
		cnt[0]+=m/2, cnt[1]+=m/2, cnt[i%2]+=m%2;
	printf("%lld",min(cnt[0],cnt[1]));
	return 0;
}