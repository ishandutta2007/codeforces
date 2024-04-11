#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const ll inf = 1e+18;

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, i, j, dpcur, dec;
	cin >> n;
	vector<ll> par(n);
	vector<ll> eff(n);
	vector<vector<ll> > chi(n);
	for (i = 0; i < n; i++) {
		cin >> par[i] >> eff[i];
		par[i]--;
		if (par[i] != -2)
			chi[par[i]].push_back(i);
	}

	vector<ll> dpin(n);
	vector<ll> dpout(n);
	for (i = n - 1; i >= 0; i--) {
		dpin[i] += eff[i];
		if (chi[i].size()) {
			dec = inf;
			for (j = 0; j < chi[i].size(); j++) {
				dpcur = max(dpin[chi[i][j]], dpout[chi[i][j]]);
				dpout[i] += dpcur;
				dpin[i] += dpcur;
				dec = min(dec, dpcur - (dpin[chi[i][j]] - eff[chi[i][j]]));
			}
			if (chi[i].size() & 1)
				dpin[i] -= dec;
			else
				dpout[i] -= dec;
		}
		else
			dpout[i] = -inf;
	}
	cout << max(dpin[0], dpout[0]);
	return 0;
}