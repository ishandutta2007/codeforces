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
const int MAXN = 120000;

int n, m;
int a[MAXN];

set<int> ss;


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		ss.insert(x);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int go = 2e9 + 100;
		auto it = ss.lower_bound(a[i]);
		if (it != ss.end())
			go = min(go, *it - a[i]);
		if (it != ss.begin()) {
			--it;
			go = min(go, a[i] - *it);
		}
		ans = max(ans, go);
	}
	cout << ans << "\n";
	return 0;
}