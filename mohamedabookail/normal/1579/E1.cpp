/**
*    author:  Mohamed Abo Okail
*    created: 30/O9/2O21
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
		deque < ll > dq;
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if(dq.empty() || x > dq.front()) {
				dq.push_back(x);
			}
			else {
				dq.push_front(x);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << dq[i] << ' ';
		}
		cout << endl;
	}
}