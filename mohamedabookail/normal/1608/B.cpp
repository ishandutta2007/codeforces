/**
*    author:  Mohamed Abo Okail
*    created: 11/12/2O21
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
		int n, a, b;
		cin >> n >> a >> b;
		if(abs(a - b) > 1) {
			cout << -1 << endl;
		}
		else if(!a && !b) {
			for (int i = 1; i <= n; i++) {
				cout << i << ' ';
			}
			cout << endl;
		}
		else if(n == 2) {
			cout << -1 << endl;
		}
		else if(n == 3) {
			if(a == 1 && b == 0) {
				cout << "1 3 2" << endl;
			}
			else if(a == 0 && b == 1) {
				cout << "3 1 2" << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if(a > b) {
			vector < ll > ar;
			ar.push_back(1);
			ar.push_back(3);
			ar.push_back(2);
			while(true) {
				ll x = ar[sz(ar) - 1] + 2, y = ar[sz(ar) - 2] + 2;
				if(y <= n) ar.push_back(y);
				if(x <= n) ar.push_back(x);
				if(x == n || y == n) break;
			}
			int aa = 0, bb = 0;
			bool ok = 0;
			for (int i = 1; i < n - 1; i++) {
				aa += (ar[i] > ar[i - 1] && ar[i] > ar[i + 1]);
				bb += (ar[i] < ar[i - 1] && ar[i] < ar[i + 1]);
				if(a == aa && b == bb) {
					ok = 1;
					sort(ar.begin() + i + 1, ar.end());
					reverse(ar.begin() + i + 1, ar.end());
					break;
				}
			}
			if(ok) {
				for (int i = 0; i < n; i++) {
					cout << ar[i] << ' ';
				}
				cout << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if(a < b) {
			vector < ll > ar;
			if(b * 2 >= n) {
				cout << -1 << endl;
			}
			else {
				ar.push_back(b * 2);
				ar.push_back(b);
				while(ar.back() != 1) {
					ar.push_back(ar.back() + b - 1);
					ar.push_back(ar.back() - b);
				}
				for (int i = b * 2 + 1; i <= n; i++) {
					ar.push_back(i);
				}
				for (int i = 0; i < n; i++) {
					cout << ar[i] << ' ';
				}
				cout << endl;
			}
		}
		else {
			vector < ll > ar;
			ar.push_back(1);
			ar.push_back(3);
			ar.push_back(2);
			while(true) {
				ll x = ar[sz(ar) - 1] + 2, y = ar[sz(ar) - 2] + 2;
				if(y <= n) ar.push_back(y);
				if(x <= n) ar.push_back(x);
				if(x == n || y == n) break;
			}
			int aa = 0, bb = 0;
			bool ok = 0;
			for (int i = 1; i < n - 1; i++) {
				aa += (ar[i] > ar[i - 1] && ar[i] > ar[i + 1]);
				bb += (ar[i] < ar[i - 1] && ar[i] < ar[i + 1]);
				if(a == aa && b == bb) {
					ok = 1;
					sort(ar.begin() + i + 1, ar.end());
					break;
				}
			}
			if(ok) {
				for (int i = 0; i < n; i++) {
					cout << ar[i] << ' ';
				}
				cout << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
}