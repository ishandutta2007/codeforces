#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1e9 + 7;
const int N = 2000;
int vals[2][N];
ll bests[2][N];

void getBests(int j, int n) {
	for (int i = 0; i < n; ++i) bests[j][i] = INF;
	
	for (int a = 0; a < n; ++a) {
		ll sum = 0;
		for (int b = a; b < n; ++b) {
			sum += vals[j][b];
			bests[j][b - a] = min(bests[j][b-a], sum);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> vals[0][i];
	for (int i = 0; i < m; ++i) cin >> vals[1][i];
	ll x;
	cin >> x;

	getBests(0, n);
	getBests(1, m);

	int res = 0;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			if (bests[0][a] * bests[1][b] <= x) {
				res = max(res, (a+1) * (b+1));
			}
		}
	}
	cout << res << '\n';
}