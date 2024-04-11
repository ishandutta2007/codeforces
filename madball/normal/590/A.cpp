#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int inf = 1e+9 + 7;
const int lim = 500500;
bool ar[lim];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c, i, j, k, n, m, p, q, v, u, x, y, z;
	int res = 0;
	string s;
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> ar[i];
	i = 0;
	for (j = 0; j < n; ++j)
		if (!j || (j == n - 1) || (ar[j] == ar[j - 1]) || (ar[j] == ar[j + 1])) {
			if (j > i + 1) {
				for (k = i; k * 2 < i + j; ++k)
					ar[k] = ar[i];
				for (; k < j; ++k)
					ar[k] = ar[j];
				res = max(res, (j - i) / 2);
			}
			i = j;
		}
	cout << res << '\n';
	for (i = 0; i < n; ++i)
		cout << int(ar[i]) << ' ';
	return 0;
}