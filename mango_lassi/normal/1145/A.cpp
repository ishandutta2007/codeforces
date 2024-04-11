#include <iostream>
using namespace std;

const int N = 1<<16;
int v[N];

bool check(int i, int l) {
	for (int d = 0; d+1 < l; ++d) {
		if (v[i+d] > v[i+d+1]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int l = n; l >= 1; l >>= 1) {
		for (int i = 0; i < n; i += l) {
			if (check(i, l)) {
				cout << l << '\n';
				exit(0);
			}
		}
	}
}