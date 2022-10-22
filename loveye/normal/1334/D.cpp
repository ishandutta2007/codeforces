#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define int long long
int n,l,r;
inline void check(int x,int ams) {
	if(l <= x && x <= r) cout << ams << ' ';
}
signed main() {
	int t;cin >> t;
	while(t--) {
		int cnt = 0;
		cin >> n >> l >> r;
		for(int i = 1;i < n;++i) {
//			cout << cnt << endl;
			if(cnt + (2 * (n-i)) < l || cnt > r) {
				cnt += (n-i) << 1;
				continue;
			}
			for(int j = i+1;j <= n;++j) {
				check(cnt + (j-i<<1)-1,i);check(cnt + (j-i<<1),j);
			}
			cnt += (n-i) << 1;
		}
		if(r == n*(n-1) + 1) cout << 1 << ' ';
		cout << endl;
	}
	return 0;
}