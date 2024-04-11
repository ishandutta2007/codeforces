/**
*    author:  Mohamed Abo Okail
*    created: 21/1O/2O21
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
		vector < ll > a(n);
		ll sum = 0;
		int indxOdd = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			if(a[i] & 1) indxOdd = i;
		}
		bool ok = 0;
		for (int i = 2; i * i <= sum; i++) {
			if(sum % i == 0) {
				ok = 1;
				break;
			}
		}
		cout << n - !ok << endl;
		for (int i = 0; i < n; i++) {
			if(!ok && i == indxOdd) continue;
			cout << i + 1 << ' ';
		}
		cout << endl;
	}
}