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
	int h, m;
	int a;
	char c;
	cin >> h >> c >> m;
	cin >> a;
	int now = h * 60 + m + a;
	now %= (24 * 60);
	h = now / 60;
	m = now % 60;
	printf("%.2d:%.2d\n", h, m);
	return 0;
}