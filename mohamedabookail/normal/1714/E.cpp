/**
*    author:  Mohamed Abo Okail
*    created: 12/O9/2O22
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
		 vector < ll > ar(n);
		 for (int i = 0; i < n; i++) {
			 cin >> ar[i];
		 }
		 sort(all(ar));
		 bool ok = 1;
		 for (int i = 0; i < n - 1; i++) {
			 if(ar[i] % 10 == 0 && ar[i] != ar[i + 1]) {
				ok = 0;
				break;
			 }
			 if(ar[i] == ar[i + 1]) continue;
			 if(ar[i] % 10 == 5 && ar[i] + 5 != ar[i + 1]) {
				ok = 0;
				break;
			 }
			 if(ar[i] % 2 == 1) {
				ar[i] += ar[i] % 10;
			 }
			 ar[i] += (ar[i + 1] - ar[i]) / 20 * 20;
			 while(ar[i] < ar[i + 1] && ar[i] % 10) {
				ar[i] += ar[i] % 10;
			 }
			 for (int j = 0; j < 10; j++) {
				 if(ar[i] == ar[i + 1]) break;
				 if(ar[i] < ar[i + 1]) {
					ar[i] += ar[i] % 10;
				 }
				 else {
					ar[i + 1] += ar[i + 1] % 10;
				 }
			 }
			 if(ar[i] != ar[i + 1]) {
				ok = 0;
				break;
			 }
		 }
		 cout << (ok ? "YES" : "NO") << endl;
	}
}