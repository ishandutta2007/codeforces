#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5,MOD = 1e9 + 7;
#define LL long long
int n;
int cnt[65][2];
LL ans,a[N];
int main() {
	ios::sync_with_stdio(0);
	int T;cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		memset(cnt,0,sizeof cnt);
		for(int i = 1;i <= n;++i) {
			cin >> a[i];
			for(int j = 0;j < 60;++j) ++cnt[j][a[i] >> j & 1];
		}
		for(int i = 1;i <= n;++i) {
			LL s1 = 0,s2 = 0;
			for(int j = 0;j < 60;++j) {
				(s1 += (1ll << j) % MOD * (a[i] >> j & 1) * cnt[j][1]) %= MOD;
				(s2 += (1ll << j) % MOD * (a[i] >> j & 1 ? n : cnt[j][1])) %= MOD;
			}
			(ans += s1 * s2) %= MOD;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}