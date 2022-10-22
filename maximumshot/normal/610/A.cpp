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
	
	int n;
	cin >> n;

	if(n % 2) cout << 0 << '\n';
	else {
		n /= 2;
		if(n % 2) cout << (n - 1) / 2 << '\n';
		else cout << (n - 2) / 2 << '\n';
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}