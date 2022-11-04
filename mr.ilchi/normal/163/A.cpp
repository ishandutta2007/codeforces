/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxN = 5000 + 10;
const int mod  = 1000 * 1000 * 1000 + 7;

string s,t;
int dp[maxN][maxN];

int main(){
	
	cin >> s >> t;

	int ns = (int)s.size();
	int nt = (int)t.size();

	int ans = 0;

	for (int i=0; i<ns; i++){
		for (int j=0; j<nt; j++){
			if (j!=0)
				dp[i][j]+= dp[i][j-1];
			if (s[i]==t[j]){
				dp[i][j]++;
				if (j!=0 && i!=0)
					dp[i][j]+= dp[i-1][j-1];
				while (dp[i][j]>=mod)
					dp[i][j]-= mod;
			}
		}
		ans+= dp[i][nt-1];
		while (ans>=mod) ans-=mod;
	}

	cout << ans << endl;

	return 0;
}