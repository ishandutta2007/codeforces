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
	
	ld n;
   ll t;
   
   cin >> n >> t;
   
   const ld val = 1.000000011;
   
   cout.precision(30);
   cout << fixed << n * pow(val, t) << '\n';
   
 	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}