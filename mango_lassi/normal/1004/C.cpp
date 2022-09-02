#include <iostream>
using namespace std;
typedef long long ll;

const int M = 1e5;
const int N = 1e5;
int cou[M + 1];
int dif[N];
int val[N];

int main() {
	int n;
	cin >> n;
	
	ll res = 0;
	int diffs = 0;
	for (int i = 0; i < n; ++i) {
		cin >> val[i];
		++cou[val[i]];
		if (cou[val[i]] == 1) {
			++dif[i];
		}
		if (i > 0) dif[i] += dif[i-1];
	}
	for (int i = 0; i <= M; ++i) cou[i] = 0;
	for (int i = n-1; i > 0; --i) {
		if (cou[val[i]] == 0) {
			res += dif[i-1];
		}
		++cou[val[i]];
	}
	cout << res << '\n';
}