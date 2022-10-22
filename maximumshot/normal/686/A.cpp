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
#include <complex>

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
	ll x;

	cin >> n >> x;
	
	char ty;
	int res = 0;

	for(int d, i = 0;i < n;i++) {
		cin >> ty >> d;
		if(ty == '+') x += d;
		else {
			if(x >= d) x -= d;
			else res++;
		}
	}

	cout << x << ' ' << res << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}