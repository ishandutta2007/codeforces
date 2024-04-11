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
typedef double ld;

using namespace std;

int n;

int main() {
	scanf("%d", &n);
	vector<int> vv;
	for (int i = 0; i < n; ++i) {
		vv.push_back(1);
		while (vv.size() > 1 && vv.back() == vv[vv.size() - 2]) {
			int x = vv.back();
			vv.pop_back();
			vv.pop_back();
			vv.push_back(x + 1);
		}
	}
	for (int i: vv)
		printf("%d ", i);
	return 0;
}