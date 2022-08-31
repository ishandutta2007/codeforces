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
int a[1000];
int b[1000];
int was[1000];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			if (b[i] == a[j])
				was[j] = 1;
		}
	cout << n - accumulate(was, was + n, 0);
	return 0;
}