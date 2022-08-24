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

int getCnt(int x) {
	if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0))
		return 366;
	else
		return 365;
}


int main() {
	int now = 2016;
	int st = 4;
	int k;
	cin >> k;
	while (k > now) {
		st = (st + getCnt(now)) % 7;
		++now;
	}
	while (k < now) {
		--now;
		st = (st - getCnt(now) + 49 * 49) % 7;
	}
	int ss = st;
	int cc = getCnt(now);
	while (true) {
		st = (st + getCnt(now)) % 7;
		++now;
		if (st == ss && getCnt(now) == cc) {
			cout << now << "\n";
			return 0;
		}
	}
	return 0;
}