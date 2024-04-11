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

const int MAXN = 2000+10;
const int inf = 1000000000;

bool mark[MAXN];
int n;
int a[MAXN],ps[MAXN],ns[MAXN];
int dp[MAXN][MAXN];

inline int ABS (int x) { return max(x, -x); }

inline int solve (vector <pii> Q){
	int n = (int)Q.size();
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			dp[i][j] = inf;
	for (int i=0; i<n; i++)
		for (int j=0; j<=i+1; j++){
			if (i==0){
				if (j==0)
					dp[i][j] = Q[i].second;
				else
					dp[i][j] = Q[i].first;
			}else{
				dp[i][j] = min(dp[i][j], dp[i-1][j] + Q[i].second);
				if (j!=0)
					dp[i][j] = min(dp[i][j], dp[i-1][j] + Q[i].first + (j-1));
			}
		}
	int ret = inf;
	for (int i=0; i<=n; i++)
		ret = min(ret, dp[n-1][i]);
	return ret;
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++) if (ABS(a[i]) > ABS(a[j])){
			if (j<i)
				ns[i]++;
			else
				ps[i]++;
		}
	}
	int ans = 0;
	for (int i=0; i<n; i++) if (!mark[i]){
		vector <pii> Q;
		for (int j=i; j<n; j++) if (a[i] == a[j]){
			Q.push_back(pii(ns[j], ps[j]));
			mark[j] = true;
		}
		ans+= solve(Q);
	}
	cout << ans << endl;
	return 0;
}