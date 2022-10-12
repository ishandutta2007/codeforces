/**
*    author:  Mohamed Abo_Okail
*    created: 19/O9/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector < ll > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(all(a));
	cout << (n - 1) / 2 << endl;
	int idx = n - 1;
	for (int i = 0; i < n; i++) {
		if(i) cout << ' ';
		if(i == idx) cout << a[i];
		else {
			cout << a[idx] << ' ';
			cout << a[i];
		}
		idx--;
		n--;
	}
	cout << endl;
}