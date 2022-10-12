/**
*    author:  Mohamed AboOkail
*    created: 15/02/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, x;
	cin >> n >> x;
	vector < pair < int, int > > a(n);
	vector < int > ans(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		sum += a[i].first;
		ans[i] = a[i].first;
	}
	if(sum > x) {
		cout << "NO" << "\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if(x - sum > a[i].second - a[i].first) {
			ans[i] = a[i].second;
			sum += a[i].second - a[i].first;
		}
		else {
			ans[i] += x - sum;
			sum = x;
			break;
		}
	}
	if(sum == x ) {
		cout << "YES" << "\n";
		for (int i = 0; i < n; i++) {
			if(i) cout << ' ';
			cout << ans[i];
		}
		cout << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
}