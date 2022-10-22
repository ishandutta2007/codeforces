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
typedef pair< ll, ll > pll;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
	
	int d[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

	int a, b;

	cin >> a >> b;

	int ans = 0;

	for(int i = a;i <= b;i++) {
		int x;
		x = i;
		while(x) ans += d[x % 10], x /= 10; 
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}