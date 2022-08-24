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

int n, d, h;


int main() {
	cin >> n >> d >> h;
	if (d > 2 * h || (d == h && d == 1 && n != 2)) {
		cout << -1 << "\n";
		return 0;
	}
	for (int i = 0; i < h; ++i)
		printf("%d %d\n", i + 1, i + 2);
	if (d == h) {
		for (int i = h + 1; i < n; ++i)
			printf("%d %d\n", 2, i + 1);
	}
	else {
		printf("1 %d\n", h + 2);
		for (int i = h + 2; i < d + 1; ++i)
			printf("%d %d\n", i, i + 1);
		for (int i = d + 1; i < n; ++i)
			printf("%d %d\n", 1, i + 1);
	}
	
	return 0;
}