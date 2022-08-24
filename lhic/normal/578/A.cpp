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

const ld INF = 1e15;

ll a, b;

int main() {
	cin >> a >> b;
	cout.setf(ios::fixed);
	cout.precision(20);
	ll k = (a - b) / (2 * b);
	ld x = INF;
	ld x2 = (ld)(a - b) / (2 * k);
	if (x2 >= b && x2 < x)
		x = x2;
	k = (a + b) / (2 * b);
	x2 = (ld)(a + b) / (2 * k);
	if (x2 >= b && x2 < x)
		x = x2;
	if (x >= INF - 1)
		cout << -1;
	else
		cout << x << "\n";

	return 0;
}