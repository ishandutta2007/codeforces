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
int a[120000];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	reverse(a, a + n);
	int cnt = 0;
	for (int i = 0; i < n && m > 0; ++i)
		++cnt, m -= a[i];
	cout << cnt << "\n";
	return 0;
}