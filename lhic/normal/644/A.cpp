#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;


int n, a, b;

vector<int> vv[200];

int main() {
	cin >> n >> a >> b;
	if (a * b < n) {
		cout << -1 << "\n";
		return 0;
	}
	int now = 1;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j)
			vv[i].push_back(now++);
		if (i % 2 == 1 && b % 2 == 0)
			rotate(vv[i].begin(), vv[i].begin() + 1, vv[i].end());
	}
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			if (vv[i][j] <= n)
				cout << vv[i][j] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
	return 0;
}