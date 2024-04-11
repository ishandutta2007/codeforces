#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int M = 2 * (int)1e5;
int cou[M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		++cou[v-1];
	}

	int res = 0;
	int rj = -1;
	int ri = -1;
	for (int j = 0; j < M; ++j) {
		if (cou[j] > 0) {
			int off = cou[j];
			int i = j+1;
			while((i < M) && (cou[i] >= 2)) {
				off += cou[i];
				++i;
			}
			if (i < M && cou[i] > 0) {
				off += cou[i];
			} else {
				--i;
			}

			if (off > res) {
				res = off;
				rj = j;
				ri = i;
			}

			if (i != j && cou[i] == 1) j = i-1;
			else j = i;

		}
	}

	cout << res << '\n';
	for (int i = rj; i <= ri; ++i) {
		cout << i+1 << ' ';
		cou[i] -= 1;
	}
	for (int i = ri; i >= rj; --i) {
		while(cou[i] > 0) {
			cout << i+1 << ' ';
			--cou[i];
		}
	}
	cout << '\n';
}