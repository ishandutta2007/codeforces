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

int w[300000];
int h[300000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &w[i], &h[i]);
	int sum = 0;
	int mx1 = 0;
	int mx2 = 0;
	for (int i = 0; i < n; ++i) {
		sum += w[i];
		mx2 = max(mx2, h[i]);
		if (mx2 > mx1)
			swap(mx1, mx2);
	}
	for (int i = 0; i < n; ++i) {
		if (h[i] == mx1)
			printf("%d ", (sum - w[i]) * mx2);
		else
			printf("%d ", (sum - w[i]) * mx1);
	}
	return 0;
}