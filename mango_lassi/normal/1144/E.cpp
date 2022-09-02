#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int C = 26;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;

	string ls, hs;
	cin >> ls >> hs;
	vector<int> lxo(k+1, 0);
	for (int i = k-1; i >= 0; --i) {
		int v1 = 'z' - ls[i];
		int v2 = hs[i] - 'a';
		if (v1 > v2) lxo[i] = -1;
		else if (v2 > v1) lxo[i] = 1;
		else lxo[i] = lxo[i+1];
	}
	
	string res(k, '_');
	int d = 0;
	for (int i = 0; i < k; ++i) {
		int d2 = hs[i] + ls[i] - 2 * (int)'a';
		if (d2 % 2 == 0) {
			d += d2 / 2;
		} else {
			if (lxo[i+1] <= 0) d += d2 / 2;
			else d += (d2 + 1) / 2;
		}
		d %= C;
		res[i] = 'a' + d;
		if (d2 % 2 == 0) d = 0;
		else d = C / 2;
	}
	cout << res << '\n';
}