/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int MAXN = 100000+10;
const int inf = (1<<30);

int n;
int a[MAXN],dp[MAXN];

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<=n; i++)
		dp[i] = inf;
	dp[0] = -inf;
	for (int i=0; i<n; i++)
		dp[upper_bound(dp, dp+n+1, a[i]) - dp] = a[i];
	cout << (lower_bound(dp, dp+n+1, inf) - dp - 1) << endl;
	return 0;
}