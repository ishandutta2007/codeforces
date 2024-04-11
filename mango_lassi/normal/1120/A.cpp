#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int T = 5 * (int)1e5;
int cou[T];
int ned[T];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, k, n, s;
	cin >> m >> k >> n >> s;

	vector<int> flowers(m);
	for (int i = 0; i < m; ++i) {
		cin >> flowers[i];
		--flowers[i];
	}

	int err = 0;
	for (int i = 0; i < s; ++i) {
		int t;
		cin >> t;
		--t;
		++ned[t];
		if (ned[t] == 1) ++err;
	}

	bool fail = true;
	for (int i = 0; i < m; ++i) {
		++cou[flowers[i]];
		if (cou[flowers[i]] == ned[flowers[i]]) --err;

		int j = i - (m - (n-1)*k);
		if (j >= 0) {
			if (cou[flowers[j]] == ned[flowers[j]]) ++err;
			--cou[flowers[j]];
		}

		if ((err == 0) && (j+1 >= 0) && ((j+1) % k == 0)) {
			int rems = (m - n * k);
			cout << rems << '\n';
			while((j < i) && (rems > 0)) {
				++j;
				if (ned[flowers[j]] == 0) {
					cout << j+1 << ' ';
					--rems;
				} else {
					--ned[flowers[j]];
				}
			}
			cout << '\n';
			fail = false;
			break;
		}
	}
	if (fail) {
		cout << "-1\n";
	}	
}