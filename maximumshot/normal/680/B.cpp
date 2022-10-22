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

	int n, a;

	cin >> n >> a;

	vec< int > mark(n + 1);

	for(int i = 1;i <= n;i++) cin >> mark[i];

	int res = 0;

	for(int	add, d = 0;a - d > 0 || a + d <= n;d++) {
		add = 0;
		if(a - d > 0 && mark[a - d]) add++;
		if(a + d <= n && d > 0 && mark[a + d]) add++; 
		if(add == 2) res += 2;
		else if(add == 1 && (d == 0 || a - d <= 0 && a + d <= n || a - d > 0 && a + d > n)) res++;
	}

	cout << res << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}