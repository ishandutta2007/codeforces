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

	int n, p, q;

	cin >> n >> p >> q;

	string s;
	cin >> s;

	for(int k = 0;k * p <= n;k++) {
		int t = n - k * p;
		if(t % q) continue;
		t /= q;
		cout << k + t << "\n";
		int j;
		for(j = 0;k > 0;k--, j += p) cout << s.substr(j, p) << "\n";
		for(;t > 0;t--, j += q) cout << s.substr(j, q) << "\n";
		return true;
	}

	cout << "-1\n";

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}