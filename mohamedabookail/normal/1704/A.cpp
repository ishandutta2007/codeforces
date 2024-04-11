/**
*    author:  Mohamed Abo Okail
*    created: 24/O9/2O22
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
		int n, m;
		cin >> n >> m;
		string a, b;
		cin >> a >> b;
		bool ok = 1;
		for (int i = m - 1; i >= 0 && ok ; i--) {
			if(i == 0) {
				bool okk = 0;
				for (int j = n - 1; j >= 0 && !okk ; j--) {
					okk |= (b[0] == a[j]);
				}
				ok &= okk;
			}
			else {
				ok &= (a[n - 1] == b[i]);
				n--;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}