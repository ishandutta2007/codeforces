#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 1 + (int)1e5;
int cou[N];
int apps[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Remove 1 -> All counts are equal
	// Choices:
	//	Max is only one, is k
	//	All are 1
	//	One is 1, all others are k
	//	One is k+1, all others are k
	// -> Enough to keep track of maximum

	int mx = 0;
	int res = 1;
	for (int i = 0; i < n; ++i) {
		int u;
		cin >> u;
		int c = apps[u];
		apps[u] = c+1;

		--cou[c];
		if (mx == c) ++mx;
		++cou[c+1];

		int tot = -cou[0];
		if ((cou[mx] == 1 && tot == 1) || (cou[1] == tot) || (cou[mx] == 1 && cou[mx-1] == tot-1) || (cou[mx] == tot-1 && cou[1] == 1)) res = i+1;
	}
	cout << res << '\n';
}