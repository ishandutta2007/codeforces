#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
using namespace std;

const int N = 2e5 + 5;
int n, q;
int pref[N];
signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1;i <= n;++i) {
		cin >> pref[i];
		if (i - 1) pref[i] += pref[i - 1];
	}
	
	int last = 0;
	while(q--) {
		int k; cin >> k;
		last += k;
		int l = 1, r = n + 1;
		while (l < r) {
			if (pref[mid] > last) r = mid;
			else l = mid + 1; 
		}
		int res = n + 1 - l;
		if (!res) res = n, last = 0;
		cout << res << endl;
	}
}