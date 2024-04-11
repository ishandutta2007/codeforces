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

ld S(ld l, int n) {
   ld alpha = 2 * pi / (ld)n;
   ld h = sqrt(l * l - l * l / (2.0 * (1 - cos(alpha))));
   ld s = (ld)n * (l * l / (2.0 * (1 - cos(alpha)))) * sin(alpha) / 2;
   return s * h / 3.0;
}

const ll mod = 100000ll;

bool solve() {
	
   vec< int > a(5);
	for(int i = 0;i < 5;i++) {
	   char x;
	   cin >> x;
	   a[i] = x - '0';
	}
	
	ll value = a[0] * 10000 + a[2] * 1000 + a[4] * 100 + a[3] * 10 + a[1];
	ll ans = 1ll;
	
	for(int i = 0;i < 5;i++) {
	   ans = (ans * value) % mod;
	}
	
	printf("%.5d\n", (int)ans);
	
 	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}