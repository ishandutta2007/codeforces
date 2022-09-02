#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int ask(int i, int j) {
	cout << "? " << i+1 << ' ' << j+1 << endl;
	int res;
	cin >> res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Ask (i, j) and (j, i). If p_i % p_j < p_j % p_i, then p_i > p_j, and p_j = p_j % p_i
	// In the end, we know the largest value is n

	int ind = 0;
	vector<int> res(n);
	for (int i = 1; i < n; ++i) {
		int a = ask(ind, i);
		int b = ask(i, ind);
		if (a < b) {
			res[i] = b;
		} else {
			res[ind] = a;
			ind = i;
		}
	}
	res[ind] = n;

	cout << "! ";
	for (int& v : res) cout << v << ' '; cout << endl;
}