#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = (int)1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	cin >> str;

	int res = 0;
	int pre = 0;
	vector<int> sum(n+1, 0);
	for (int i = 0; i < n; ++i) {
		sum[i+1] = sum[i] + (str[i] == '(' ? 1 : -1);
		if (sum[i+1] >= 0) {
			if (pre < i) res += i+1-pre;
			pre = i+1;
		}
	}

	if (sum[n] != 0) cout << -1 << '\n';
	else cout << res << '\n';

}