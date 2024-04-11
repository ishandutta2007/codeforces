/**
*    author:  Mohamed Abo Okail
*    created: 21/O2/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n, k;
	cin >> n >> k;
	if(n < k) {
		cout << "NO" << endl;
		return 0;
	}
	vector < ll > a, ans;
	ll flag = 1;
	while(flag < 1e9) {
		a.push_back(flag);
		flag *= 2;
	}
	for (int i = sz(a) - 1; i >= 0; i--) {
		while(n >= a[i]) {
			ans.push_back(a[i]);
			n -= a[i];
		}
	}
	if(sz(ans) > k) {
		cout << "NO" << endl;
		return 0;
	}
	int indx = 0;
	while(sz(ans) < k) {
		if(ans[indx] > 1) {
			ans[indx] /= 2;
			ans.push_back(ans[indx]);
		}
		else {
			indx++;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < k; i++) {
		cout << ans[i] << ' ';
	}
}