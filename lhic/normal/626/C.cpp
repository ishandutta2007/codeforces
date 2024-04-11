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


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int n2 = 0;
	int n3 = 0;
	int n6 = 0;
	for (int i = 1; i <= 6000100; ++i) {
		if (i % 6 == 0)
			++n6;
		else if (i % 2 == 0)
			++n2;
		else if (i % 3 == 0)
			++n3;
		int l2 = max(0, n - n2);
		int l3 = max(0, m - n3);
		if (n6 >= l2 + l3) {
			cout << i << "\n";
			return 0;
		}
	}
	return 0;
}