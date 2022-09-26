#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 105;
map<int,bool> mp;

int n;
int a[N];
signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0;i < n;++i) {
		cin >> a[i];
		mp[a[i]] = true;
	}
	vector<int> res;
	for (int i = 0;i < n;++i) {
		res.clear();
		res.pb(a[i]);
		bool found = true;
		for (int j = 0;j < n - 1;++j) {
			if (mp[res[j] * 2]) {
				res.pb(res[j] * 2);
				continue;
			}
			
			if (res[j] % 3 == 0 && mp[res[j] / 3]) {
				res.pb(res[j] / 3);
				continue;
			}
			found = false;
			break;
		}
		if (found) {
			for (int j = 0;j < n;++j) cout << res[j] << ' ';
		}
	}
}