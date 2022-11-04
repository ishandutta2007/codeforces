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

int n,m;
int a[1<<20],dp[1<<20];

int main(){
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> a[i];
		double temp; cin >> temp;
	}
	int ans = 0;
	for (int i=0; i<n; i++){
		dp[i] = 1;
		for (int j=0; j<i; j++) if (a[j]<=a[i]){
			dp[i] = max(dp[i], dp[j]+1);
		}
		ans = max(ans, dp[i]);
	}
	cout << n-ans << endl;
	return 0;
}