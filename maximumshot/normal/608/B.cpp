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
	
	string a, b;
	cin >> a >> b;

	ll ans = 0;
	int n = (int)b.size();

	vec< int > c(n);
	for(int j = 0, i = 0;i < n;i++) {
		j += b[i] - '0';
		c[i] = j;
	}

	int x = (int)b.size() - (int)a.size();

	for(int i = 0;i < (int)a.size();i++) {
		// [i .. i + x]
		int t = c[i + x] - (i?c[i - 1] : 0);
		if(a[i] == '0') ans += t;
		else ans += x + 1 - t;
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}