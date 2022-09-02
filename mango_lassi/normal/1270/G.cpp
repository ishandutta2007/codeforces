#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		// i-n <= ai <= i-1
		// ai' = i - ai
		// 1 <= ai' <= n, ai'
		// Add edge from i to ai', and find cycle.
		// Then in that cycle j_{k+1} = j_{k} - a_{j_k}
		// Hence \sum_{j \in C} j = \sum_{j \in C} j - a_{j} -> \sum_{j \in C} a_{j} = 0

		int n;
		cin >> n;

		vector<int> tar(n);
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			tar[i] = i - a;
		}
		
		int j = 0;
		int x = 0;
		vector<int> ind(n, -1);
		while(ind[x] == -1) {
			ind[x] = j;
			x = tar[x];
			++j;
		}

		cout << j - ind[x] << '\n';
		int y = x;
		do {
			cout << y+1 << ' ';
			y = tar[y];
		} while (y != x);
		cout << '\n';
	}
}