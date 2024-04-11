#include <iostream>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

const int N = 2000;
int vals[N];

void addVal(int x, int i) {
	cout << 1 << ' ' << i << ' ' << x << '\n';
	for (int j = 0; j < i; ++j) vals[j] += x;
}

void takeMod(int x, int i) {
	cout << 2 << ' ' << i << ' ' << x << '\n';
	for (int j = 0; j < i; ++j) vals[j] %= x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> vals[i];

	cout << n+1 << '\n';
	int x = 5 * (int)1e5;
	addVal(x, n);
	for (int i = 0; i < n; ++i) {
		takeMod(vals[i] - (i + 1), i+1);
	}

	// for (int i = 0; i < n; ++i) cout << vals[i] << ' '; cout << '\n';
}