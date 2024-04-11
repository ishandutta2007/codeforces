/**
*    author:  Mohamed AboOkail
*    created: 14/01/2O21
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
		string a, b;
		cin >> a >> b;
		if(a.size() > b.size()) {
			swap(a, b);
		}
		string ans = a;
		while(ans.size() % b.size() != 0) {
			ans += a;
		}
		bool ok = 1;
		for (int i = 0; i < ans.size(); i += b.size()) {
			string x;
			for (int j = i; j < i + b.size(); j++) {
				x.push_back(ans[j]);
			}
			if(x != b) ok = 0;
		}
		cout << (ok ? ans : "-1") << "\n";
	}
}