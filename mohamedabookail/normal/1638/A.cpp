/**
*    author:  Mohamed Abo Okail
*    created: 16/O2/2O22
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
		vector < int > a(n), b;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		b = a;
		sort(all(b));
		int cur = 0, indx = 0;
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			if(a[i] != b[i] && !ok) {
				cur = b[i];
				ok = 1;
				indx = i;
			}
			if(a[i] == cur) {
				reverse(a.begin() + indx, a.begin() + i + 1);
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}