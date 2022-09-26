#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	long long x,d;
	cin >> x >> d;
	long long cur = 1;
	vector<long long> ans;
	for (int i = 29;i > 0;--i) {
		long long tmp = (1LL << i) - 1;
		while(x >= tmp) {
			x -= tmp;
			for (int j = 0;j < i;++j) ans.push_back(cur);
			cur += d;
		}
	}
	
	cout << ans.size() << endl;
	for (int i = 0;i < ans.size();++i) cout << ans[i] << ' ';
}