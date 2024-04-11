/**
*    author:  Mohamed AboOkail
*    created: 16/02/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector < long long > a(n);
		map < long long , int > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		vector < long long > x;
		for(auto it : mp) {
			x.push_back(it.second);
		}
		vector < long long > ans;
		sort(x.begin(), x.end());
		for (int i = 0; i < x.size(); i++) {
			ans.push_back(n - (x.size() - i) * x[i]);
		}
		cout << *min_element(ans.begin(), ans.end()) << "\n";
	}
}