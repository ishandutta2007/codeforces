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
	cin >> n;
	if (n <= 2) {
		cout << 1 << "\n";
		for (int i = 0; i < n; ++i)
			cout << 1 << " ";
		cout << "\n";
		return 0;
	}
	printf("2\n");
	for (int i = 2; i <= n + 1; ++i) {
		int fl = 0;
		for (int j = 2; j * j <= i; ++j)
			if (i % j == 0) {
				fl = 1;
				break;
			}
		if (fl) {
			printf("2 ");
		}
		else {
			printf("1 ");
		}
	}
	printf("\n");
	return 0;
}