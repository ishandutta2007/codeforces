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

	int n, x, c = 0, mn = inf + 1;
	ll sum = 0;
	scanf("%d", &n);

	for(int i = 0;i < n;i++) {
		scanf("%d", &x);
		sum += x;
		if(x % 2) {
			c++;
			mn = min(mn, x);
		}
	}

	if(c % 2) sum -= mn;

	cout << sum << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}