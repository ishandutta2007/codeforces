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

int n;

ll sum = 0;

ll a[120000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	ll cnt = 0;
	ll go = sum / n;
	sort(a, a + n);
	reverse(a, a + n);
	int gg = sum % n;
	for (int i = 0; i < gg; ++i)
		cnt += abs(a[i] - (go + 1));
	for (int i = gg; i < n; ++i)
		cnt += abs(a[i] - go);

	cout << cnt / 2 << "\n";
	return 0;
}