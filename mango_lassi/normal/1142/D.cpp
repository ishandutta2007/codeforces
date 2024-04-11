#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 1e5;
const int K = 11;
int ans[N+1][K];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();

	vector<int> mp = {-1, 10, 0, 2, 5, 9, 3, 9, 5, 2, 0};

	ll res = 0;
	for (int i = n-1; i >= 0; --i) {
		for (int k = 0; k < K; ++k) {
			ans[i][k] = 1;
			if (i+1 == n) continue;

			int d = (str[i+1] - '0');
			if (d < k) {
				int tk = (mp[k] + d) % 11;
				ans[i][k] = 1 + ans[i+1][tk];
			}
		}
		int di = (str[i] - '0');
		if (di != 0) {
			res += ans[i][di];
		}
	}
	cout << res << '\n';
}