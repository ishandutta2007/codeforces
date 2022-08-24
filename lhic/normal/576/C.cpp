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


vector<pair<int, int> > ur[2000];
int x[1200000];
int y[1200000];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		ur[x[i] / 1000].push_back(make_pair(y[i], i));
	}
	for (int i = 0; i <= 1000; i += 2)
		sort(ur[i].begin(), ur[i].end());
	for (int i = 1; i <= 1000; i += 2) {
		sort(ur[i].begin(), ur[i].end());
		reverse(ur[i].begin(), ur[i].end());
	}
	for (int i = 0; i <= 1000; ++i) {
		for (int j = 0; j < (int)ur[i].size(); ++j)
			printf("%d ", ur[i][j].second + 1);
	}
	return 0;
}