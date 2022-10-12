/**
*    author:  Mohamed AboOkail
*    created: 11/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long n;
	cin >> n;
	vector < long long > a, b, c, ans;
	a.push_back(4);
	a.push_back(7);
	c = a;
	for (int i = 0; i < 10; i++) {
		b.clear();
		b = c;
		c.clear();
		for (int j = 0; j < b.size(); j++) {
			a.push_back(b[j] * 10 + 4);
			a.push_back(b[j] * 10 + 7);
			c.push_back(b[j] * 10 + 4);
			c.push_back(b[j] * 10 + 7);
		}
	}
	for (int i = 0; i < a.size(); i++) {
		long long cur = a[i], x = 0, y = 0;
		while(cur) {
			x += cur % 10 == 4;
			y += cur % 10 == 7;
			cur /= 10;
		}
		if(x == y) {
			ans.push_back(a[i]);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		if(ans[i] >= n) {
			cout << ans[i] << "\n";
			break;
		}
	}
}