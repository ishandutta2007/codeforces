/**
*    author:  Mohamed Abo Okail
*    created: 18/O5/2O21
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
	
	int t; cin >> t;
	while(t--) {
		int n, x; cin >> n >> x;
		vector < int > a(n);
		ll sum = 0, summ = 0;
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(all(a));
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if(sum == x) {
				swap(a[i], a[n - 1]);
				break;
			}
		}

		for (int i = 0; i < n; i++) {
			summ += a[i];
			if(summ == x) {
				ok = 0;
				break;
			}
		}

		if(!ok) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << a[i] << ' ';
			}
			cout << endl;
		}
	}
}