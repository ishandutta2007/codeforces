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

bool solve() {
	
	int n, k, a, b, c, d;

	cin >> n >> k >> a >> b >> c >> d;

	if(k <= n || n == 4) {
		cout << -1 << '\n';
		return true;
	}

	cout << a << ' ' << c << ' ';

	for(int i = 1;i <= n;i++) {
		if(i == a || i == b || i == c || i == d) continue;
		cout << i << ' ';
	}

	cout << d << ' ' << b << '\n';

	cout << c << ' ' << a << ' ';

	for(int i = 1;i <= n;i++) {
		if(i == a || i == b || i == c || i == d) continue;
		cout << i << ' ';
	}

	cout << b << ' ' << d << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}