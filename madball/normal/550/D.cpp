#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

void write(ll k, ll off) {
	ll i, j;
	for (i = 4; i <= k + 2; i++) {
		cout << 1 + off << ' ' << i + off << '\n';
		cout << 2 + off << ' ' << i + off << '\n';
		cout << 3 + off << ' ' << i + off << '\n';
	}
	cout << 2 + off << ' ' << 3 + off << '\n';
	for (i = 4; i <= k + 2; i++)
		for (j = 1; j < (k - 1) / 2; j++)
			cout << i + off << ' ' << ((i + j) - 4) % (k - 1) + 4 + off << '\n';
}

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll k;
	cin >> k;
	if (!(k & 1)) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	if (k == 1) {
		cout << "2 1\n1 2";
		return 0;
	}

	cout << k * 2 + 4 << ' ' << (k + 2) * k << '\n';
	write(k, 0);
	write(k, k + 2);
	cout << 1 << ' ' << k + 3 << '\n';

	return 0;
}