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
int a[120000];

int main() {
	scanf("%d", &n);
	int ans = 1;
	int now = 1;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1]) {
			++now;
			ans = max(ans, now);
		}
		else {
			now = 1;
		}
	}
	cout << ans << "\n";
	return 0;
}