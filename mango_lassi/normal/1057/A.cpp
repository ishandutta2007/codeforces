#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> par(n, 0);
	for (int i = 1; i < n; ++i) cin >> par[i];
	for (int i = 0; i < n; ++i) --par[i];
	vector<int> res;
	for (int i = n-1; i != -1; i = par[i]) res.push_back(i);
	reverse(res.begin(), res.end());
	for (auto it : res) cout << it+1 << ' '; cout << '\n';
}