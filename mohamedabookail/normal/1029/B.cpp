/**
*    author:  Mohamed Abo Okail
*    created: 1O/O6/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector < ll > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(all(a));
	ll ans = 1, cnt = 1;
	for (int i = 1; i < n; i++) {
		if(a[i] <= a[i - 1] * 2) {
			cnt++;
		}
		else {
			ans = max(ans, cnt);
			cnt = 1;
		}
	}
	cout << max(ans, cnt) << endl;
}