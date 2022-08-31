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


int main() {
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << max(abs(x1 - x2), abs(y1 - y2)) << "\n";
	return 0;
}