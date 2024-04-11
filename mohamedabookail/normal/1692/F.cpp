/**
*    author:  Mohamed Abo Okail
*    created: 27/O6/2O22
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
		map < int, int > mp;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mp[x % 10]++;
		}
		bool ok = 0;
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					if(i != j && i != k && j != k && mp[i] && mp[j] && mp[k]) {
						ok |= (i + j + k) % 10 == 3;
					}
					else if(i == j && j == k && mp[i] >= 3) {
						ok |= (i + j + k) % 10 == 3;
					}
					else if(i == j && i != k && mp[i] >= 2 && mp[k]) {
						ok |= (i + j + k) % 10 == 3;
					}
					else if(i == k && i != j && mp[i] >= 2 && mp[j]) {
						ok |= (i + j + k) % 10 == 3;
					}
					else if(j == k && i != j && mp[j] >= 2 && mp[i]) {
						ok |= (i + j + k) % 10 == 3;
					}
				}
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}