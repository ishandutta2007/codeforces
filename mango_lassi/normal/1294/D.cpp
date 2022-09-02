#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	int m = 0;
	vector<int> cou(x, 0);
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		++cou[v % x];
		while(cou[m % x] >= m/x + 1) ++m;
		cout << m << '\n';
	}
}