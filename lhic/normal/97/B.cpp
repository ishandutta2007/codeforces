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

vector<pair<int, int> > ans;

pair<int, int> a[12000];
int n;

void run(int l, int r) {
	if (l + 1 == r) {
		ans.push_back(a[l]);
		return;
	}
	int m = (l + r) >> 1;
	run(l, m);
	run(m, r);
	int x = a[m].first;
	for (int i = l; i < r; ++i)
		ans.push_back(make_pair(x, a[i].second));
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a, a + n);
	run(0, n);
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	printf("%d\n", (int)ans.size());
	for (auto i: ans)
		printf("%d %d\n", i.first, i.second);
	return 0;
}