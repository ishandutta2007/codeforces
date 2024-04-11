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
	ll n;
	cin >> n;
	ll l = 0;
	while (l * (l + 1) / 2 < n)
		++l;
	--l;
	n -= l * (l + 1) / 2;
	cout << n << "\n";
	return 0;
}