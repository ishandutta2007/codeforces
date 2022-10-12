/**
*    author:  Mohamed Abo Okail
*    created: 14/O7/2O21
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
	
	int t; cin >> t;
	while(t--) {
		int n, a, b; cin >> n >> a >> b;
		string s; cin >> s;

		vector < int > zero, one;
		int cnt1 = 0, cnt2 = 0;
		int sum0 = 0, sum1 = 0;
		for (int i = 0; i < n; i++) {
			if(s[i] == '0') {
				cnt1++;
				if(cnt2) {
					one.push_back(cnt2);
					cnt2 = 0;
				}
				sum0++;
			}
			else {
				cnt2++;
				if(cnt1) {
					zero.push_back(cnt1);
					cnt1 = 0;
				}
				sum1++;
			}
		}
		if(cnt1) zero.push_back(cnt1);
		if(cnt2) one.push_back(cnt2);

		if(b >= 0) {
			cout << (n * a) + (n * b) << endl;
		}
		else if(a >= 0 && b < 0) {
			ll ans1 = 0, ans2 = 0;
			if(sum0 > sum1) {
				for (int i = 0; i < sz(one); i++) {
					ans1 += one[i] * a + b;
				}
				ans1 += sum0 * a + b;
			}
			else {
				for (int i = 0; i < sz(zero); i++) {
					ans1 += zero[i] * a + b;
				}
				ans1 += sum1 * a + b;
			}
			
			if(sz(zero) > sz(one)) {
				for (int i = 0; i < sz(one); i++) {
					ans2 += one[i] * a + b;
				}
				ans2 += sum0 * a + b;
			}
			else {
				for (int i = 0; i < sz(zero); i++) {
					ans2 += zero[i] * a + b;
				}
				ans2 += sum1 * a + b;
			}
			cout << max(ans1, ans2) << endl;
		}
		else {
			ll ans = 0;
			if(sz(zero) > sz(one)) {
				for (int i = 0; i < sz(one); i++) {
					ans += one[i] * a + b;
				}
				ans += sum0 * a + b;
			}
			else {
				for (int i = 0; i < sz(zero); i++) {
					ans += zero[i] * a + b;
				}
				ans += sum1 * a + b;
			}
			cout << ans << endl;
		}
	}
}