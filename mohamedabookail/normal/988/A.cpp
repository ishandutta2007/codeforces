/**
 *    author:  Mohamed Abo_Okail
 *    created: 21/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vector < int > v(n), ans;
	map < int, int > mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]]++;
	}
	if(mp.size() < k) { cout << "NO"; }
	else {
		for (int i = 0; i < n; i++) {
			if(mp[v[i]] > 0) {
				ans.push_back(i + 1);
				mp[v[i]] = 0;
			}
		}
		sort(ans.begin(), ans.end());
		cout << "YES" << endl;
		for (int i = 0; i < k; i++) {
			cout << ans[i] << ' ';
		}
	}
}