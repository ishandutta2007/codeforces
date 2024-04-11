/**
*    author:  Mohamed Abo Okail
*    created: O2/O5/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

long long nCr(long long n, long long r) {
	long long ans = 1;
	long long div = 1; 
	for (long long i = r + 1; i <= n; i++) {
		ans = ans * i;
		ans /= div;
		div++;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		string a, b;
		cin >> a >> b;
		int cnt = 0;
		for (int i = 0; i < sz(b); i++) {
			cnt += (b[i] == 'a');
		}
		if(cnt == 0) {
			ll ans = 1;
			for (int i = 1; i <= sz(a); i++) {
				ans += nCr(sz(a), i);
			}
			cout << ans << endl;
		}
		else if(sz(b) == 1 && cnt == 1) {
			cout << 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}