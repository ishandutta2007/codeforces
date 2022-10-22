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

	int n, k;

	cin >> n >> k;

	vec< int > c(n);
	for(int i = 0;i < n;i++) {
		cin >> c[i];
	}

	vec< vec< char > > dp(k + 1, vec< char >(k + 1));

	dp[0][0] = 1;

	for(int i = 0;i < n;i++) {
		for(int x = k;x >= 0;x--) {
			for(int y = k;y >= 0;y--) {
				if(x >= c[i] && dp[x - c[i]][y] || y >= c[i] && dp[x][y - c[i]]) dp[x][y] = 1;
			}
		}
	}

	int res = 0;

	for(int x = 0;x <= k;x++) {
		if(dp[x][k - x]) res++;
	}

	cout << res << '\n';

	for(int x = 0;x <= k;x++) {
		if(dp[x][k - x]) cout << x << ' ';
	}

	cout << '\n';


	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}