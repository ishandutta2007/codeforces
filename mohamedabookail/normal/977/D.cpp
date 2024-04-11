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
	
	int n; cin >> n;
	vector < ll > a(n);
	deque < ll > ans;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(all(a));
	reverse(all(a));
	ans.push_back(a[0]);
	a[0] = -1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if(a[j] == -1) continue;
			if(a[j] * 3 == ans.back()) {
				ans.push_back(a[j]);
				a[j] = -1;
				continue;
			}
			if(ans.back() * 2 == a[j]) {
				ans.push_back(a[j]);
				a[j] = -1;
				continue;
			}
			if(a[j] * 2 == ans.front()) {
				ans.push_front(a[j]);
				a[j] = -1;
				continue;
			}
			if(ans.front() * 3 == a[j]) {
				ans.push_front(a[j]);
				a[j] = -1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}