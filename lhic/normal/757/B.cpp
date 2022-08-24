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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MX = 120000;

int n;
int a[MX];
int cc[MX];

int main() {
	int ans = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n; ++i) {
		int tmp = a[i];
		for (int j = 2; j * j <= tmp; ++j) {
			if (tmp % j != 0)
				continue;
			while (tmp % j == 0)
				tmp /= j;
			++cc[j];
		}
		if (tmp != 1)
			++cc[tmp];
	}
	for (int i = 1; i < MX; ++i)
		ans = max(ans, cc[i]);
	cout << ans << "\n";
	return 0;
}