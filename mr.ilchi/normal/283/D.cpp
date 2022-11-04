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

int n;
int p[10000], dp[10000];
LL  a[10000];

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
		while (a[i]%2==0){
			a[i]/=2; p[i]++;
		}
	}
	for (int i=0; i<n; i++){
		dp[i] = 1;
		for (int j=0; j<i; j++){
			if (a[j]%a[i]!=0) continue;
			if ((i-j<=p[i]) && ((i-j)!=p[i]-p[j]))
				continue;
			dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << (n - *max_element(dp, dp+n)) << endl;
	return 0;
}