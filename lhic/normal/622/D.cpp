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

int main() {
	scanf("%d", &n);
	vector<int> vv;
	int l = 1;
	while (l < n)
		vv.push_back(n - l), l += 2;
	for (int i = (int)vv.size() - 1; i >= 0; --i)
		printf("%d ", vv[i]);
	for (int i = 0; i < (int)vv.size(); ++i)
		printf("%d ", vv[i]);
	vv.clear();
	l = 2;
	while (l < n)
		vv.push_back(n - l), l += 2;
	for (int i = (int)vv.size() - 1; i >= 0; --i)
		printf("%d ", vv[i]);
	printf("%d ", n);
	for (int i = 0; i < (int)vv.size(); ++i)
		printf("%d ", vv[i]);
	printf("%d\n", n);
	return 0;
}