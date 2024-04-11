#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0;i < n;++i) {
		int x; cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	cout << a[(n - 1) / 2];
}