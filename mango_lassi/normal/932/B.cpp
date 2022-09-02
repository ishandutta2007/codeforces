#include <iostream>
using namespace std;

int g(int num) {
	if (num < 10) return num;
	int prod = 1;
	while(num > 0) {
		int nxt = num / 10;
		int dig = num - nxt * 10;
		if (dig) prod *= dig;
		num = nxt;
	}
	return g(prod);
}

const int N = 1e6 + 10;
const int K = 10;
int count[N][K];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i < N; ++i) {
		int val = g(i);
		if (val < 10) {
			++count[i][val];
		}
		for (int j = 0; j < K; ++j) {
			count[i][j] += count[i-1][j];
		}
	}
	int q;
	cin >> q;
	for (int j = 0; j < q; ++j) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << (count[r][k] - count[l-1][k]) << '\n';
	}
}