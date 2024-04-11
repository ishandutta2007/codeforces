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
typedef pair<int,int> pii;
typedef complex<double> point;

const int MAXN = 1000+10;
const int MAXV = 10000+10;
const int mod = 1000000007;

int n,res,sum;
int a[MAXN];
int dp[MAXN][4*MAXV];

inline void add (int &A, const int B) { A+= B; if (A>=mod) A-= mod; }

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++){
		sum+= a[i-1];
		for (int j=-sum; j<=sum; j++){
			add(dp[i][j+MAXV], dp[i-1][j+a[i-1]+MAXV]);
			add(dp[i][j+MAXV], dp[i-1][j-a[i-1]+MAXV]);
		}
		add(dp[i][a[i-1]+MAXV], 1);
		add(dp[i][-a[i-1]+MAXV],1);
		add(res,dp[i][MAXV]);
	}
	cout << res << endl;
	return 0;
}