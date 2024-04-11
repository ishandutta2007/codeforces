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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
	
	int n;
	cin >> n;

	vec< int > a(1010);

	for(int x, i = 0;i < n;i++) {
		cin >> x;
		a[x]++;
	}

	int ans = 0;

	while(1) {
		int mn = inf, len = 0;
		for(int i = 1;i <= 1000;i++) {
			if(a[i] > 0) mn = min(mn, a[i]), len++;
		}
		if(mn == inf) break;
		ans += mn * (len - 1);
		for(int i = 1;i <= 1000;i++) {
			if(a[i] > 0) a[i] -= mn;
		}
	}

	printf("%d\n", ans);
	
	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}