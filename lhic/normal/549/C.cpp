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


int n, k;
int c1, c2;
int aa;
int main() {
	scanf("%d%d", &n, &k);
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		if (a % 2 == 0)
			++c1;
		else
			++c2;
	}


	int k2 = n - k;

	if (k2 % 2 == 1) {
		if (k % 2 == 0) {
			if (c1 == c2) {
				if (k2 / 2 >= min(c1, c2) - 1)
					aa = 0;
				else
					aa = 1;
			}
			else
				if (k2 / 2 >= min(c1, c2))
					aa = 0;
				else
					aa = 1;
		}
		else {
			if (k2 / 2 >= c2)
				aa = 0;
			else
				aa = 1;
		}
	}
	else {
		if (k % 2 == 0)
			aa = 0;
		else {
			if (k2 / 2 >= c1)
				aa = 1;
			else
				aa = 0;
		}
	}

	if (n == k) {
		if (c2 % 2 == 0)
			aa = 0;
		else
			aa = 1;
	}

	if (aa == 0) {
		cout << "Daenerys";
	}
	else
		cout << "Stannis";
	


	return 0;
}