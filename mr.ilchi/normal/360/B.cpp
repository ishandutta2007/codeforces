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

int n,k;
int a[2005];
int dp[2005];

int main(){
	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int lo = 0, hi = 2000000000, ans = -1;
	while (lo <= hi){
		int mid = ((LL)lo + hi) / 2;
		memset(dp, 0, sizeof dp);
		for (int i=n-1; i>=0; i--){
			dp[i] = 1;
			for (int j=i+1; j<n; j++)
				if (abs(a[j]-a[i]) <= (LL)(j-i)*(LL)mid)
					dp[i] = max(dp[i], dp[j]+1);
		}
		if (n-(*max_element(dp, dp+n)) <= k)
			ans=mid, hi=mid-1;
		else
			lo = mid+1;
	}
	cout << ans << endl;
	return 0;
}