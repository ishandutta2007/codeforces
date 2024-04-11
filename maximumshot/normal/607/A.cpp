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

	vec< pii > a(n);

	for(int i = 0;i < n;i++) cin >> a[i].first >> a[i].second;

	sort(ALL(a));

	vec< int > dp(n, inf);

	dp[0] = 0;

	for(int i = 1;i < n;i++) {

		int bl, br, bm, j;

		bl = 0, br = i;
		
		while(br - bl > 1) {
			bm = (bl + br) >> 1;
			if(a[i].first - a[bm].first <= a[i].second) br = bm;
			else bl = bm + 1;
		}

		j = (a[i].first - a[bl].first <= a[i].second?bl : br);

		dp[i] = (j?dp[j - 1] : 0) + i - j;
		//cout << i << " " << j << "\n";
	}

	//for(auto i : dp) cout << i << " ";
	//cout << '\n';

	int ans = n;

	for(int i = 0;i < n;i++) {
		// [0 .. i]
		ans = min(ans, dp[i] + n - i - 1);
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}