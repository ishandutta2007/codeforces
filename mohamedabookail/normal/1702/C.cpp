/**
*    author:  Mohamed Abo Okail
*    created: 18/O9/2O22
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
		int n, k;
		cin >> n >> k;
		vector < int > ar(n);
		map < int , int > first, last;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			if(!first[ar[i]]) {
				first[ar[i]] = i + 1;
			}
			last[ar[i]] = i + 1;
		}
		while(k--) {
			int a, b;
			cin >> a >> b;
			if(first[a] && first[b]) {
				cout << (first[a] <= last[b] ? "YES" : "NO") << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}