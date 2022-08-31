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

const int MAXN = 2e5;

int n;
int upl[MAXN];
int upr[MAXN];
int h[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &h[i]);
	upl[0] = min(h[0], 1);
	for (int i = 1; i < n; ++i)
		upl[i] = min(upl[i - 1] + 1, h[i]);
	upr[n - 1] = min(h[n - 1], 1);
	for (int i = n - 2; i >= 0; --i)
		upr[i] = min(upr[i + 1] + 1, h[i]);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, min(upl[i], upr[i]));
	cout << ans << "\n";
	return 0;
}