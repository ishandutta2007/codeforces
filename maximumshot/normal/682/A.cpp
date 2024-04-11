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
		
	int n, m;

	cin >> n >> m;

	ll res = 0;

	vec< int > c1(5), c2(5);
	
	for(int x = 1;x <= n;x++) c1[x % 5]++;
	for(int x = 1;x <= m;x++) c2[x % 5]++;
	
	for(int i = 0;i < 5;i++) {
		for(int j = 0;j < 5;j++) {
			if((i + j) % 5 == 0) res += 1ll * c1[i] * c2[j];
		}
	}

	cout << res << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}