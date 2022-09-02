#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
bool checkZero(vector<int> cou) {
	if (cou[1] + 1 < cou[0]) return false;
	if (cou[0] == cou[1] + 1 && cou[2] == 0 && cou[3] == 0) return true;
	cou[1] -= cou[0];
	cou[0] = 0;

	if (cou[2] + 1 < cou[1]) return false;
	if (cou[1] == cou[2] + 1 && cou[3] == 0) return true;
	cou[2] -= cou[1];
	cou[1] = 0;

	if (cou[3] + 1 < cou[2]) return false;
	if (cou[2] == cou[3] + 1) return true;
	cou[3] -= cou[2];
	cou[2] = 0;

	if (cou[0] != 0 || cou[1] != 0 || cou[2] != 0 || cou[3] != 0) return false;
	else return true;
}
*/

vector<int> buildZero(vector<int> cou, int x) {
	vector<int> res;

	if (cou[x] == 0) return {};

	while(true) {
		res.push_back(x);
		--cou[x];
		if (x > 0 && cou[x-1] > 0) {
			--x;
		} else if (x+1 < 4 && cou[x+1] > 0) {
			++x;
		} else break;
	}
	for (auto v : cou) {
		if (v != 0) return {};
	}
	return res;
}
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> cou(4);
	cin >> cou[0] >> cou[1] >> cou[2] >> cou[3];

	vector<int> res;
	for (int j = 0; res.empty() && j < 4; ++j) res = buildZero(cou, j);

	if (res.empty()) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (auto v : res) cout << v << ' '; cout << '\n';
	}
}