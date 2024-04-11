#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a(n), b(n);
	int sa = 0;
	for (int &x : a) {
		cin >> x;
		sa += x;
	}
	int sb = 0;
	for (int &y : b) {
		cin >> y;
		sb += y;
	}
	if (sa >= sb) cout << "Yes";
	else cout << "No"; 
}