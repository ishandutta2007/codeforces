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
int n0 = 2;
int n1 = 1;
int en[100][100];

int g0() {
	n0 += 2;
	return n0 - 2;
}

int g1() {
	n1 += 2;
	return n1 - 2;
}
int n;

int main() {
	cin >> n;
	int now = 1;
	for (int i = 0; i < n; ++i) {
		int x = now / 2;
		int st = n / 2;
		for (int j = st - x; j <= st + x; ++j)
			en[i][j] = 1;
		if (i * 2 + 1 < n)
			now += 2;
		else
			now -= 2;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (en[i][j])
				printf("%d ", g1());
			else
				printf("%d ", g0());
		}
		printf("\n");
	}
	return 0;
}