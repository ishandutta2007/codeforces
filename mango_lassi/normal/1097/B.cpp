#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 16;
const int M = 360;
bool can[N][M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	can[0][0] = true;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		for (int j = 0; j < M; ++j) {
			if (can[i-1][j]) {
				can[i][(j + x) % M] = true;
				can[i][(j + M-x) % M] = true;
			}
		}
	}
	if (can[n][0]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}