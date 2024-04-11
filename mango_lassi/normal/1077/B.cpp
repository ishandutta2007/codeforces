#include <iostream>
using namespace std;
typedef long long ll;

const int N = 100;
int state[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> state[i];
	int res = 0;
	for (int i = 2; i < n; ++i) {
		if (state[i] && state[i-2] && (!state[i-1])) {
			++res;
			state[i] = 0;
		}
	}
	cout << res << '\n';
}