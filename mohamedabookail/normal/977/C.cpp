/**
*    author:  Mohamed Abo Okail
*    created: O1/11/2O21
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
	
	int n, k; cin >> n >> k;
	vector < ll > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(all(a));
	if(!k) {
		cout << (a[0] > 1 ? 1 : -1) << endl;
	}
	else if(n == k) {
		cout << a[n - 1] << endl;
	}
	else if(a[k - 1] != a[k]) {
		cout << a[k - 1] << endl;
	}
	else {
		cout << -1 << endl;
	}
}