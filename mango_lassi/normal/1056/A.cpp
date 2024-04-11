#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int R = 100;
int cou[R + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			int v;
			cin >> v;
			++cou[v];
		}
	}

	for (int i = 1; i <= R; ++i) {
		if (cou[i] == n) cout << i << ' ';
	}
	cout << '\n';
}