#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main() {
	cin.tie(&cout);
	pair <int, int> qs[] = {{1, 2}, {3, 4}, {1, 5}, {3, 5}};
	vector <int> ans;
	vector <int> a = {4, 8, 15, 16, 23, 42};
	for (auto i : qs) {
		cout << "? " << i.first << " " << i.second << "\n";
		int an;
		cin >> an;
		ans.push_back(an);
	}
	do {
		bool flag = true;
		for (int i = 0; i < 4; i++) {
			if (a[qs[i].first - 1] * a[qs[i].second - 1] != ans[i]) {
				flag = false;
			}
		}
		if (flag) {
			cout << "!";
			for (auto i : a) {
				cout << " " << i;
			}
			cout << '\n';
			return 0;
		}
	} while (next_permutation(a.begin(), a.end()));

}