#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
int conns[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		++conns[a];
		++conns[b];
	}

	bool fail = false;
	for (int i = 0; i < n; ++i) {
		if (conns[i] == 2) fail = true;
	}
	if (fail) cout << "NO\n";
	else cout << "YES\n";
}