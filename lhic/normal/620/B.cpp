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
typedef double ld;

using namespace std;

int dd[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
	int sum = 0;
	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; ++i) {
		int now = i;
		while (now) {
			sum += dd[now % 10];
			now /= 10;
		}
	}
	cout << sum << "\n";
	return 0;
}