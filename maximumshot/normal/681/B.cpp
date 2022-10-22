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

const ll x = 1234567ll;
const ll y = 123456ll;
const ll z = 1234ll;

bool solve() {
	
	ll n;
	cin >> n;

	for(ll a = 0;a * x <= n;a++) {
		for(ll b = 0;b * y <= n - a * x;b++) {
			ll c = n - a * x - b * y;
			if(c % z == 0) {
				cout << "YES\n";
				return true;
			}
		}
	}

	cout << "NO\n";

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}