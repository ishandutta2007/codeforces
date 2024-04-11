#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
using namespace std;
typedef long long ll;
const ll inf = 1000100;
int ar[inf];

int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int i, j, n, k, m, l, r = 0, a, b, c, x, y, z;
	string s;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> a;
		++ar[a];
	}
	for (i = 0; i < inf - 1; ++i) {
		ar[i + 1] += ar[i] >> 1;
		ar[i] = ar[i] & 1;
		if (ar[i])
			++r;
	}
	cout << r;
	return 0;
}