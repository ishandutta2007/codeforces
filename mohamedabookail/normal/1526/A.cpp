/**
*    author:  Mohamed Abo Okail
*    created: O4/O6/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector < ll > ar(n * 2);
		for (int i = 0; i < n * 2; i++) {
			cin >> ar[i];
		}
		sort(all(ar));
		for (int i = 0; i < n; i++) {
			cout << ar[i] << ' ' << ar[i + n] << ' ';
		}
		cout << endl;
	}
}