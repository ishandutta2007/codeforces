/**
*    author:  Mohamed Abo_Okail
*    created: 28/O9/2O2O
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
	map < ll, bool > mp;
	ll sum = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if(!sum || mp[sum]) {
			cnt++;
			mp.clear();
			sum = a[i];
		}
		mp[sum] = 1;
	}
	cout << cnt << endl;
}