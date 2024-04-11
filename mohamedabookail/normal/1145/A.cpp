/**
*    author:  Mohamed Abo Okail
*    created: 31/O3/2O22
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
	ll ans = 1, x = 2;
	while(x <= 16) {
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			cnt += (a[i] >= a[i - 1]);
			if((i + 1) % x == 0) {
				if(cnt == x) {
					ans = x;
				}
				cnt = 0;
			}
		}
		x *= 2;
	}
	cout << ans << endl;
}