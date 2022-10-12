/**
*    author:  Mohamed Abo Okail
*    created: 21/O7/2O22
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
	
	int n, m;
	cin >> n >> m;
	vector < ll > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector < ll > cur1(n, 0), cur2(n, 0);
	for (int i = 1; i < n; i++) {
		if(a[i] < a[i - 1]) {
			cur1[i] = a[i - 1] - a[i];
		}
	}
	for (int i = n - 2; i >= 0 ; i--) {
		if(a[i + 1] > a[i]) {
			cur2[i] = a[i + 1] - a[i];
		}
	}
	for (int i = 1; i < n; i++) {
		cur1[i] += cur1[i - 1];
	}
	for (int i = n - 2; i >= 0 ; i--) {
		cur2[i] += cur2[i + 1];
	}
	while(m--) {
		int x, y;
		cin >> x >> y;
		if(x < y) {
			cout << cur1[--y] - cur1[--x] << endl; 
		}
		else {
			cout << cur2[--y] - cur2[--x] << endl;
		}
	}
}