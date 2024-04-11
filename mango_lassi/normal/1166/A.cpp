#include <iostream>
using namespace std;
using ll = long long;

const int C = 26;
int cou[C];

ll choose(int a) {
	return a * (a-1) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		++cou[str[0] - 'a'];
	}

	ll res = 0;
	for (int i = 0; i < C; ++i) {
		res += choose(cou[i] / 2) + choose((cou[i] + 1) / 2);
	}
	cout << res << '\n';
}