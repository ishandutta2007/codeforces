#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int armax(vector<ll> const &ar) {
	int res = 0;
	for (int i = 1; i < ar.size(); ++i)
		if (ar[i] > ar[res])
			res = i;
	return res;
}

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	ll n, m, i, j;
	cin >> n >> m;
	vector<ll> city(n, 0);
	vector<ll> cur(n);

	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j)
			cin >> cur[j];
		++city[armax(cur)];
	}
	cout << armax(city) + 1;
	return 0;
}