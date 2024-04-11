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


int main() {
	int n;
	scanf("%d", &n);
	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int c = 0;
		if (x1 % 2 != 0)
			c += 1;
		if (y1 % 2 != 0)
			c += 2;
		printf("%d\n", c + 1);
	}
	return 0;
}