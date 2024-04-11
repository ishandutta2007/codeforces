/**
*    author:  Mohamed Abo Okail
*    created: 22/O4/2O22
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
	
	int n;
	cin >> n;
	vector < ll > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(all(a));
	ll ans = a[0];
	for (int i = 1; i < n; i++) {
		if(a[i] != a[i - 1]) {
			ans = a[i];
			break;
		}
	}
	if(ans == a[0]) {
		cout << "NO" << endl;
	}
	else {
		cout << ans << endl;
	}
}