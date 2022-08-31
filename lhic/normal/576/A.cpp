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

int n;
int aa[2000];
vector<int> vv;

int main() {
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		if (aa[i])
			continue;
		for (int j = i + i; j <= n; j += i)
			aa[j] = 1;
		int j = i;
		while (j <= n)
			vv.push_back(j), j *= i;
	}
	cout << vv.size() << "\n";
	for (int i = 0; i < (int)vv.size(); ++i)
		cout << vv[i] << " ";
	return 0;
}