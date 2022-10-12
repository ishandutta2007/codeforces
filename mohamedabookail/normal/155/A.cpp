/**
*    author:  Mohamed Abo_Okail
*    created: O1/11/2O2O
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
	vector < int > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int cnt = 0, mx = v[0], mn = v[0];
	for (int i = 1; i < n; i++) {
		if(v[i] > mx) {
			cnt++;
			mx = v[i];
		}
		if(v[i] < mn) {
			cnt++;
			mn = v[i];
		}
	}
	cout << cnt << endl;
}