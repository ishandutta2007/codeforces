#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int INF = (int)1e9 + 7;
const int N = 2000;
int offs[N][10];
bool dp[N+1][N+1];

vector<int> nums = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;

		int val = 0;
		for (int j = 6; j >= 0; --j) {
			if (str[j] == '1') val |= 1 << (6-j);
		}
		for (int j = 0; j < 10; ++j) {
			if ((val | nums[j]) != nums[j]) offs[i][j] = INF;
			else offs[i][j] = __builtin_popcount(nums[j] ^ val);
		}
	}

	dp[n][0] = 1;
	for (int i = n-1; i >= 0; --i) {
		for (int a = 0; a <= k; ++a) {
			for (int j = 0; j < 10; ++j) {
				int t = a - offs[i][j];
				if (t >= 0 && dp[i+1][t]) dp[i][a] = 1;
			}
		}
	}

	if (! dp[0][k]) cout << -1 << '\n';
	else {
		string res(n, '_');
		for (int i = 0; i < n; ++i) {
			for (int j = 9; j >= 0; --j) {
				int t = k - offs[i][j];
				if (t >= 0 && dp[i+1][t]) {
					res[i] = '0' + j;
					k = t;
					break;
				}
			}
		}
		cout << res << '\n';
	}
}