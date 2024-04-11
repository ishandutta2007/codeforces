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

int a, n;
int ans[12000];
vector<int> vv;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a, vv.push_back(a);
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			int mn = 0;
			for (int j = 1; j < (int)vv.size(); ++j)
				if (vv[j] < vv[mn])
					mn = j;
			cout << vv[mn] << " ";
			vv.erase(vv.begin() + mn);
		}
		else {
			int mn = 0;
			for (int j = 1; j < (int)vv.size(); ++j)
				if (vv[j] > vv[mn])
					mn = j;
			cout << vv[mn] << " ";
			vv.erase(vv.begin() + mn);
		}
	}
	cout << "\n";
	return 0;
}