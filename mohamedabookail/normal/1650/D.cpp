/**
*    author:  Mohamed Abo Okail
*    created: O9/O3/2O22
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
		deque < ll > dq(n);
		for (int i = 0; i < n; i++) {
			cin >> dq[i];
		}
		vector < ll > ans(n + 1);
		for (int i = n; i > 0 ; i--) {
			while(dq.back() != i) {
				ans[i]++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
			dq.pop_back();
		}
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}