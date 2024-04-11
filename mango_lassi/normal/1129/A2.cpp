#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 5000;
int cou[N];
int lst[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) lst[i] = n;

	// Out of stations with most candies, find the one with latest last endpoint
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		int d = (b < a ? n - (a - b) : b - a);
		++cou[a];
		lst[a] = min(lst[a], d);
	}
	for (int s = 0; s < n; ++s) {
		int ans = 0;
		for (int j = 0; j < n; ++j) {
			int i = (s + j) % n;
			if (cou[i] == 0) continue;
			ans = max(ans, j + (cou[i] - 1)*n + lst[i]);
		}
		cout << ans << ' ';
	}
	cout << '\n';
}