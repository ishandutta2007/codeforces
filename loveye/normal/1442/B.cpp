#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5,MOD = 998244353,inv2 = MOD+1>>1;
int t,n,a[N],k,b[N],ans;
int vis[N],pos[N];
int main() {
	ios::sync_with_stdio(0);
	int t;cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1;i <= n;++i)
			cin >> a[i],pos[i] = 0;
		for(int i = 1;i <= k;++i)
			cin >> b[i],pos[b[i]] = i;
		int ok = 1;
		a[0] = a[n+1] = pos[0] = pos[n+1] = n+1;
		for(int i = 1;i <= n;++i) {
			if(pos[a[i]] && pos[a[i]] < pos[a[i+1]] && pos[a[i]] < pos[a[i-1]]) {
				ok = 0;
				break;
			}
		}
		if(!ok) {
			cout << 0 << endl;
			continue;
		}
		ans = 1;
		for(int i = 1;i <= n;++i)
			if(pos[a[i]] && !pos[a[i-1]]) ans = ans * 2 % MOD;
		if(pos[a[n]]) ans = ans * 1ll * inv2 % MOD;
		cout << ans << endl;
	}
	return 0;
}