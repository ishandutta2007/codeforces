#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

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

	int n;
	cin >> n;

	int cnt = 0;

	for(int x, i = 0;i < n;i++) {
		cin >> x;
		if(x == 0) cnt++;
	}

	if(n == 1) {
		cout << (cnt == 0?"YES" : "NO") << '\n';
	}else {
		cout << (cnt == 1?"YES" : "NO") << '\n';
	}

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}