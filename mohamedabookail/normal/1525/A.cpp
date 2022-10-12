/**
*    author:  Mohamed Abo Okail
*    created: 18/O5/2O21
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
		if(100 % n == 0) {
			cout << 100 / n << endl;
		}
		else {
			int a = n, b = 100 - n;
			for (int i = 1; i <= 100; i++) {
				for (int j = 2; j <= 100; j++) {
					if(a % j == 0 && b % j == 0) {
						a /= j;
						b /= j;
					}
				}
			}

			cout << a + b << endl;
		}
	}
}