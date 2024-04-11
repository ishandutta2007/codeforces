#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool vis(int year) {
	return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

int c(int year) {
	return vis(year) ? 366 : 365;
}

bool solve() {
	
	int y;

	cin >> y;

	for(int f = c(y) % 7, x = y + 1;;f = (f + c(x++)) % 7) {
		if(f == 0 && vis(y) == vis(x)) {
			cout << x << '\n';
			return true;
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}