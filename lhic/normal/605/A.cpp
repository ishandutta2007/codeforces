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

int p[120000];
int lst[120000];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int xx = lst[p[i] - 1] + 1;
		lst[p[i]] = xx;
		ans = max(ans, xx);
	}
	cout << n - ans << endl;
	return 0;
}