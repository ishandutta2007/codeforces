#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = acos(-1.0);

bool solve() {

    int a, b, c;
    int x, y, z;

    cin >> a >> b >> c;
    cin >> x >> y >> z;

    int can = max(0, a - x) / 2 +
              max(0, b - y) / 2 +
              max(0, c - z) / 2;

    int need = max(0, x - a) + max(0, y - b) + max(0, z - c);

    cout << (can >= need?"Yes" : "No") << "\n";

	return true;
}

int main() {

    //while(solve());
	solve();

	return 0;
}