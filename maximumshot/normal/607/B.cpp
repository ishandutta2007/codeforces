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
    vec< int > a(n);
    for(auto & i : a) cin >> i;

    vec< vec< int > > dp(n, vec< int >(n, inf));

    for(int i = n - 1;i >= 0;i--) {
        for(int j = i;j < n;j++) {
            if(i == j) dp[i][j] = 1;
            else if(i + 1 == j) dp[i][j] = (a[i] == a[j]?1 : 2);
            else {
                for(int k = i;k < j;k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
                if(a[i] == a[j]) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                }
            }
        }
    }

    cout << dp[0][n - 1] << "\n";

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}