#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int mi(int a) {
	if(a >= 10) return min(mi(a / 10),a % 10);
	return a;
}
int mx(int a) {
	if(a >= 10) return max(mx(a / 10),a % 10);
	return a;
}
signed main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--) {
		int a,k;
		cin >> a >> k;
		for(int i = 2;i <= k;++i) {
			if(mi(a) == 0) break;
			a = a + mi(a) * mx(a);
		}
		cout << a << endl;
	}
	return 0;
}