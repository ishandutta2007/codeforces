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

const int MAXN = 4000+10;

int n,a[MAXN];
int nex[MAXN][MAXN],dp[MAXN][MAXN];
map <int, int> mp;

int main(){
	cin >> n;
	int cnt = 0;
	for (int i=0; i<n; i++){
		cin >> a[i];
		if (mp.find(a[i])==mp.end()){
			mp[a[i]] = cnt;
			cnt++;
		}
		a[i] = mp[a[i]];
	}
	for (int i=0; i<cnt; i++)
		nex[n][i] = -1;
	for (int i=n-1; i>=0; i--){
		for (int j=0; j<cnt; j++)
			nex[i][j] = nex[i+1][j];
		nex[i][a[i]] = i;
	}
	int ans = 0;
	for (int i=n-1; i>=0; i--){
		for (int j=0; j<cnt; j++) if (j!=a[i]){
			if (nex[i][j] == -1)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[nex[i][j]][a[i]] + 1;
			ans = max(ans, dp[i][j]);
		}
	}
	for (int i=0; i<cnt; i++)
		ans = max(ans, count(a,a+n,i));
	cout << ans << endl;
	return 0;
}