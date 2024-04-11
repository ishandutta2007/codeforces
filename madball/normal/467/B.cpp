#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long lint;

int main() {
	lint n, m, k, c = 0;
	cin >> n >> m >> k;
	lint ar[1005];
	for (int i = 0; i <= m; i++)
		cin >> ar[i];

	for (int i = 0; i < m; i++) {
		lint curc = 0;
		for (int j = 0; j < n; j++)
			if (((ar[i] >> j) & 1) != ((ar[m] >> j) & 1))
				curc++;
		if (curc <= k)
			c++;
	}
	cout << c << '\n';

	return 0;
}