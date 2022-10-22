#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,a[N];
int main() {
	ios::sync_with_stdio(0);
	int t;cin >> t;
	while(t--) {
		int ans1 = 0,ans2 = 0;
		cin >> n;
		for(int i = 0,x;i < n;++i) {
			cin >> x;
			if((i & 1) && !(x & 1)) ++ans1;
			else if(!(i & 1) && (x & 1)) ++ans2;
		}
		if(ans1 != ans2) cout << -1 << endl;
		else cout << ans1 << endl;
	}
	return 0;
}