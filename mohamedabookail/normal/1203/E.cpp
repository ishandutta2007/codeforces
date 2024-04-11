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
	
	int n; cin >> n;
	map < ll , bool > mp;
	vector < ll > a(n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(all(a));
	for (int i = 0; i < n; i++) {
		if(a[i] > 1 && !mp[a[i] - 1]) {
			mp[a[i] - 1] = 1;
			ans++;
		}
		else if(!mp[a[i]]) {
			mp[a[i]] = 1;
			ans++;
		}
		else if(!mp[a[i] + 1]) {
			mp[a[i] + 1] = 1;
			ans++;
		}
	}
	cout << ans << endl;
}