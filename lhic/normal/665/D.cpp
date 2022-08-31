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

const int MX = 3000000;

int pr[MX];
vector<int> vv;

int main() {
	pr[0] = 1;
	pr[1] = 1;
	for (int i = 2; i < MX; ++i) {
		if (pr[i])
			continue;
		for (ll j = (ll)i * i; j < MX; j += i)
			pr[j] = 1;
	}
	int n;
	int c1 = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x == 1)
			++c1;
		vv.push_back(x);
	}
	if (c1 != 0) {
		for (int i = 0; i < n; ++i)
			if (vv[i] != 1) {
				if (!pr[vv[i] + 1]) {
					cout << c1 + 1 << "\n";
					for (int j = 0; j < c1; ++j)
						cout << 1 << " ";
					cout << vv[i] << "\n";
					return 0;
				}
			}
		if (c1 >= 2) {
			cout << c1 << "\n";
			for (int j = 0; j < c1; ++j)
				cout << 1 << " ";
			cout << "\n";
			return 0;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			if (!pr[vv[i] + vv[j]]) {
				cout << 2 << "\n";
				cout << vv[i] << " " << vv[j] << "\n";
				return 0;
			}
		}
	cout << 1 << "\n";
	cout << vv[0] << "\n";
	return 0;
}