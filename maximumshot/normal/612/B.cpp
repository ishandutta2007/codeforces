#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>

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

	vec< int > f(n);
	
	for(int x, i = 0;i < n;i++) {
		cin >> x;
		f[x - 1] = i;
	}

	ll ans = 0;

	for(int i = 1;i < n;i++) {
		ans += abs(f[i] - f[i - 1]);
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}