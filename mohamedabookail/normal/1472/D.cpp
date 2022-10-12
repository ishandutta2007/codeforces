/**
*    author:  Mohamed AboOkail
*    created: 04/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector < int > odd, even;
		for (int i = 0; i < n; i++) {
			int oo;
			cin >> oo;
			if(oo & 1) odd.push_back(oo);
			if(!(oo & 1)) even.push_back(oo);
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		reverse(odd.begin(), odd.end());
		reverse(even.begin(), even.end());
		long long a = 0, b = 0;
		int idx1 = 0, idx2 = 0;
		for (int i = 1; i <= n; i++) {
			if(i & 1) {
				if(idx1 < even.size() && idx2 < odd.size()) {
					if(even[idx1] >= odd[idx2]) {
						a += even[idx1];
						idx1++;
					}
					else {
						idx2++;
					}
				}
				else if(idx1 < even.size()) {
					a += even[idx1];
					idx1++;
				}
				else {
					idx2++;
				}
			}
			else {
				if(idx1 < even.size() && idx2 < odd.size()) {
					if(odd[idx2] >= even[idx1]) {
						b += odd[idx2];
						idx2++;
					}
					else {
						idx1++;
					}
				}
				else if(idx2 < odd.size()) {
					b += odd[idx2];
					idx2++;
				}
				else {
					idx1++;
				}
			}
		}
		cout << (a > b ? "Alice" : (a < b ? "Bob" : "Tie")) << endl;
	}
}