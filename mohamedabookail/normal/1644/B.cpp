/**
*    author:  Mohamed Abo Okail
*    created: 21/O2/2O22
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
		deque < int > dq(n);
		for (int i = n; i > 0; i--) {
			dq[n - i] = i;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << dq[j] << ' ';
			}
			dq.push_front(dq.back());
			dq.pop_back();
			if(n == 3 && i == 1) {
				swap(dq[1], dq[2]);
			}
			cout << endl;
		}
	}
}