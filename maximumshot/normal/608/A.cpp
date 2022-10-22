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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
	
	int n, s;

	cin >> n >> s;

	for(int i = 0;i < n;i++) {
		int f, t;
		cin >> f >> t;
		s = max(s, f + t);
	}

	cout << s << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}