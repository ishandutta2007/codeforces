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

const int inf = 1000000000;

int k,n,maxb,t;
int b[123456];
vector < vector <int> > next,dp;

inline int main2(){
	for (int i=0; i<n; i++){
		cin >> b[i]; b[i]--;
	}
	fill(next[n].begin(), next[n].begin()+maxb, inf);
	for (int i=n-1; i>=0; i--){
		fill(next[i].begin(), next[i].begin()+maxb, inf);
		for (int j=0; j<maxb; j++) if (next[i+1][j]!=inf)
			next[i][j] = next[i+1][j] + 1;
		next[i][b[i]] = 0;
	}
	for (int i=1; i<n; i++)
		for (int j=0; j<maxb; j++) if (next[i][j]==inf && next[0][j]!=inf)
			next[i][j] = next[0][j] + n-i;
	for (int i=1; i<=n; i++){
		for (int j=0; j<maxb; j++){
			dp[i][j] = inf;
			if (i==1){
				if (next[0][j] != inf)
					dp[i][j] = next[0][j];
				dp[i][j] = min(dp[i][j], dp[i][max(0,j-1)]);
			}else if (j>0){
				dp[i][j] = dp[i][j-1];
				if (dp[i-1][j-1]!=inf && next[dp[i-1][j-1]%n][j]!=inf)
					dp[i][j] = min(dp[i][j], dp[i-1][j-1] + next[dp[i-1][j-1]%n][j]);
			}
		}
	}
	for (int i=n; i; i--) if (*min_element(dp[i].begin(), dp[i].begin()+maxb) < n*t)
		return i;
	return 0;
}

int main(){
	cin >> k >> n >> maxb >> t;
	t = min(t, maxb);
	dp.resize(n+1, vector <int> (maxb, 0));
	next.resize(n+1, vector <int> (maxb, 0));
	for (int o=0; o<k; o++)
		cout << main2() << endl;
	return 0;
}