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
	cin >> n;
	for (int i = 2; i < (1 << (n + 1)); ++i)
		cin >> a[i];
	int k = 1 << n;
	int ans = 0;

	for (int i = k - 1; i >= 1; --i) {
		ans += max(a[i * 2], a[i * 2 + 1]) - min(a[i * 2], a[i * 2 + 1]);
		a[i] += max(a[i * 2], a[i * 2 + 1]);
	}
	cout << ans;


	return 0;
}