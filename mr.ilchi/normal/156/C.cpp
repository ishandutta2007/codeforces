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

const int mod = 1000 * 1000 * 1000 + 7;

int test;
int dp[200][200 * 26];
string s;

int go (int n , int cost){
	
	if (cost < 0)
		return 0;

	if (dp[n][cost]!=-1)
		return dp[n][cost];

	if (n==0)
		return cost == 0;

	int ret = 0;

	for (int i=1; i<=26; i++){
		ret+= go(n-1,cost-i);
		ret%=mod;
	}

	return dp[n][cost] = ret;
}

int main(){
	
	ios_base::sync_with_stdio(false);

	cin >> test;

	memset (dp , -1 , sizeof dp);

	for (int o=1; o<=test; o++){
		cin >> s;
		int val = 0;
		for (int i=0; i<s.size(); i++)
			val+= (s[i]-'a'+1);
		cout << (go((int)s.size(),val)-1+mod)%mod << endl;
	}

	return 0;
}