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
int cnt[1200000];
int w[1200000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &w[i]), ++cnt[w[i]];
	int ans = 0;
	for (int i = 0; i < 1100000; ++i) {
		while (cnt[i] >= 2)
			cnt[i] -= 2, cnt[i + 1] += 1;
		ans += cnt[i];
	}
	cout << ans << "\n";

	return 0;
}