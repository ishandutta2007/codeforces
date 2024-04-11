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

int n, m;
int cnt[10000];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		--a;
		++cnt[a];
	}
	int ans = 0;
	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j < m; ++j)
			ans += cnt[i] * cnt[j];
	cout << ans << "\n";
	return 0;
}