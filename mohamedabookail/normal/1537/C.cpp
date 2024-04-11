/**
*    author:  Mohamed Abo Okail
*    created: 18/01/2O22
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
		ll cur = 2e9, aa = 0, bb = 0;
		bool ok1 = 0, ok2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(all(a));
		for (int i = 0; i < n - 1; i++) {
			if(a[i + 1] - a[i] < cur) {
				cur = a[i + 1] - a[i];
				aa = a[i];
				bb = a[i + 1];
			}
		}
		deque < ll > dq;
		for (int i = 0; i < n; i++) {
			if(a[i] == aa && !ok1) {
				ok1 = 1;
				continue;
			}
			if(a[i] == bb && !ok2) {
				ok2 = 1;
				continue;
			}
			dq.push_back(a[i]);
		}
		int s = 0;
		while(sz(dq) && aa > dq.front() && s < n - 2) {
			dq.push_back(dq.front());
			dq.pop_front();
			s++;
		}
		dq.push_front(aa);
		dq.push_back(bb);
		for (int i = 0; i < n; i++) {
			cout << dq[i] << ' ';
		}
		cout << endl;
	}	
}