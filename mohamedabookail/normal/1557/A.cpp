/**
*    author:  Mohamed Abo Okail
*    created: 09/O8/2O21
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
		int n; cin >> n;
		vector < double > a(n), ans;
		cout << fixed << setprecision(12);
		double sum = 0.00, cur = 0.00;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(all(a));
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}
		sum -= a[0];
		cur = a[0];
		for (int i = 1; i < n; i++) {
			ans.push_back((cur / double(i)) + (sum / double(n - i)));
			cur += a[i];
			sum -= a[i];
		}
		sort(all(ans));
		cout << ans[sz(ans) - 1] << endl;
	}
}