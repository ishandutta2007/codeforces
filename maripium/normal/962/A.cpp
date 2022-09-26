#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0;i < n;++i) {
		int x;	cin >> x;
		if (i != 0) x += a.back();
		a.push_back(x);
	}
	int ans = lower_bound(a.begin(),a.end(),(a.back() + 1)/ 2) - a.begin() + 1;
	cout << ans;
}