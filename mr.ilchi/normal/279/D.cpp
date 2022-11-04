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

const int MAXN = 20+5;

bool dp[1<<23];
int n;
int a[MAXN],func[MAXN][MAXN];

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			for (int k=0; k<n; k++) if (a[i] + a[j] == a[k])
				func[i][k]|=(1<<j);
	dp[1] = true;
	for (int mask = 0; mask < (1<<(n-1)); mask++) if (dp[mask]){
		int last = 0;
		for (int i=0; i<n; i++) if (mask & (1<<i))
			last = i+1;
		bool can = false;
		for (int i=0; i<n; i++) if (mask & (1<<i))
			if (func[i][last] & mask)
				can = true;
		if (can){
			for (int i=0; i<n; i++) if (mask & (1<<i))
				dp[mask ^ (1<<i) ^ (1<<last)] = true;
			dp[mask ^ (1<<last)] = true;
		}
	}
	int ans = (1<<30);
	for (int mask = (1<<(n-1)); mask < (1<<n); mask++) if (dp[mask])
		ans = min(ans, __builtin_popcount(mask));
	cout << ((ans!=(1<<30)) ? ans : -1) << endl;
	return 0;
}