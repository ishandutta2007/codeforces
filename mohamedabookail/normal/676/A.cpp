/**
*    author:  Mohamed Abo Okail
*    created: O7/O4/2O22
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
 
	int n;
	cin >> n;
	vector < ll > a(n);
	int ind1 = 0, ind2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] == 1) {
			ind1 = i + 1;
		}
		if(a[i] == n) {
			ind2 = i + 1;
		}
	}
	if(ind1 > ind2) {
		swap(ind1, ind2);
	}
	cout << n - min(ind1 - 1, n - ind2) - 1 << endl;
}