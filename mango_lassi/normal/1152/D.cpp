#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 2 * (1 + (int)1e3);
ll dp0[N][N]; // Maximum pairing of trie subtree with i open and j left, such that edge to parent is taken
ll dp1[N][N]; // Maximum pairing of trie subtree with i open and j left, such that edge to parent is not taken

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	n *= 2;

	dp0[0][0] = 0;
	dp1[0][0] = 1;
	for (int b = 1; b <= n; ++b) {
		for (int a = 0; a <= b; ++a) {
			if (a == b) {
				dp1[a][b] = (1 + dp0[a-1][b-1]) % MOD;
				dp0[a][b] = max(dp0[a-1][b-1], dp1[a-1][b-1]);
			} else if (a == 0) {
				dp1[a][b] = (1 + dp0[a+1][b-1]) % MOD;
				dp0[a][b] = max(dp0[a+1][b-1], dp1[a+1][b-1]);
			} else {
				dp1[a][b] = (1 + dp0[a-1][b-1] + dp0[a+1][b-1]) % MOD;
				dp0[a][b] = (max((dp0[a-1][b-1] + dp1[a+1][b-1]), (dp1[a-1][b-1] + dp0[a+1][b-1]))) % MOD;
			}
		}
	}
	cout << dp0[0][n] << '\n';
}