#include <iostream>
using namespace std;
typedef long long ll;

const int INF = 1e9 + 7;
const int N = 5000;
int ps[2*N];
int tar[2*N];
bool used[2*N];

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < 2*n; ++i) tar[i] = -1;
	for (int i = 0; i < 2*n; ++i) cin >> ps[i];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		tar[a] = b;
		tar[b] = a;
	}

	// Start by picking all the pairs, by picking the stronger of the two.
	// Then pick the strongest remaining hero while possible.
	int t;
	cin >> t;

	for (int j = 0; j < 2*n; ++j) {
		if (t == 1) {
			int pick = -1;
			int val = -1;
			for (int i = 0; i < 2*n; ++i) {
				if (used[i]) continue;
				if (tar[i] != -1) {
					int o = tar[i];
					if (used[o]) {
						pick = i;
						break;
					} else {
						if (ps[i] < ps[o]) pick = o;
						else pick = i;
						val = INF;
					}
				} else {
					if (ps[i] > val) {
						val = ps[i];
						pick = i;
					}
				}
			}
			used[pick] = true;
			cout << pick+1 << endl;

			t = 2;
		} else {
			int x;
			cin >> x;
			if (x == -1) break;
			--x;
			used[x] = true;

			t = 1;
		}
	}
}