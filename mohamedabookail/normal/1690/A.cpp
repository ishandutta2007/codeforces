/**
*    author:  Mohamed Abo Okail
*    created: 22/O9/2O22
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
		int n;
		cin >> n;
		int a = n / 3, b = n / 3, c = n / 3;
		if(n % 3 == 0) {
			b++;
			c--;
		}
		else if(n % 3 == 1) {
			b += 2;
			c--;
		}
		else {
			b += 2;
			a++;
			c--;
		}
		cout << a << ' ' << b << ' ' << c << endl;
	}
}