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


int n;
int main() {
	cin >> n;
	for (int m = 1; m <= 1000; ++m) {
		int x = n * m + 1;
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) {
				cout << m << "\n";
				return 0;
			}
		}
	}
	return 0;
}