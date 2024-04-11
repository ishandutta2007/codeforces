/**
*    author:  Mohamed Abo Okail
*    created: 19/O9/2O22
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
		int n, k;
		cin >> n >> k;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll sum = 0;
		for (int i = 0; i < k; i++) {
			int x = 1;
			while(i + k * x < n) {
				if(a[i] < a[i + k * x]) {
					a[i] = a[i + k * x];
				}
				x++;
			}
			sum += a[i];
		}
		cout << sum << endl;
	}
}