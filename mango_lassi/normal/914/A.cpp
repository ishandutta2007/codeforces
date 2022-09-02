#include <iostream>
using namespace std;

const int N = (1e6) + 1;
bool sqr[N];

int main() {
	for (int i = 0; i * i < N; ++i) {
		sqr[i * i] = true;
	}
	int n;
	cin >> n;
	
	int res = -N;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v < 0 || !sqr[v]) {
			res = max(res, v);	
		}
	}
	cout << res << '\n';
}