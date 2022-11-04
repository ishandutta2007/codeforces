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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int mod = 1000 * 1000 * 1000 + 7;

int k;
string s1,s2;

int main(){
	
	cin >> s1 >> s2 >> k;

	int n = (int)s1.size();

	int dp0=1 , dp1=0;

	for (int i=1; i<=k; i++){
		int tmpdp0 = ((ll)dp1 * (n-1ll))%mod;
		int tmpdp1 = ((ll)dp1 * (n-2ll) + dp0)%mod;
		dp0 = tmpdp0;
		dp1 = tmpdp1;
	}

	int ans = 0;

	if (s1==s2)
		ans = dp0;

	s1+=s1;

	for (int i=1; i<n; i++) if (s1.substr(i,n)==s2)
		ans = (ans + dp1) % mod;

	cout << ans << endl;

	return 0;
}