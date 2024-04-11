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

bool solve() {

	int n, h, k;

	scanf("%d %d %d", &n, &h, &k);

	ll res = 0;

	vec< int > a(n);

	for(int i = 0;i < n;i++) scanf("%d", &a[i]);

	ll s = 0, t; 

	for(int i = 0;i < n;i++) {
		if(s + a[i] <= h) s += a[i];
		else {
			// s - t * k + a[i] <= h
			// t * k >= s + a[i] - h
			t = (s + a[i] - h + k - 1) / (ll)k;
			res += t;
			s -= t * k;
			if(s < 0) s = 0;
			s += a[i];
		}
	}

	res += (s + k - 1) / (ll)k;

	cout << res << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}