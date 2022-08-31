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

vector<int> vv;

multiset<int> ss;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int a;
			scanf("%d", &a);
			ss.insert(a);
		}
	while (!ss.empty()) {
		int x = *ss.rbegin();
		printf("%d ", x);
		for (int i = 0; i < (int)vv.size(); ++i)
			ss.erase(ss.find(__gcd(x, vv[i]))), ss.erase(ss.find(__gcd(x, vv[i])));
		vv.push_back(x);
		ss.erase(ss.find(x));
	}
	return 0;
}