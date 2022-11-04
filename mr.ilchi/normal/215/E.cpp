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

ll lo,hi;
ll dp[100],cnt[100];
vector <int> Q;

ll IE (int pos, int len, int sgn){
	if (pos == (int)Q.size())
		return cnt[len] * sgn;
	return IE(pos+1,len,sgn) + IE(pos+1,__gcd(len,Q[pos]),-sgn);
}

ll go (ll MAX){
	if (MAX==0)
		return 0;
	ll temp = MAX;
	string s; while (temp) { s+=char('0'+temp%2); temp/=2; }
	reverse(s.begin(),s.end());
	Q.clear();
	int len = (int)s.size();
	for (int i=1; i<len; i++) if (len%i==0){
		string tmp = s.substr(0,i);
		while ((int)tmp.size()<len)
			tmp+= s.substr(0,i);
		cnt[i] = (MAX >> (len-i)) - (1ll<<(i-1)) + 1;
		if (s<tmp)
			cnt[i]--;
		Q.push_back(i);
	}
	ll ret = 0;
	for (int i=1; i<len; i++)
		ret+= (1ll<<(i-1))-dp[i];
	return ret + IE(0,0,-1);
}

int main(){
	dp[1] = 1;
	for (int i=2; i<=60; i++){
		dp[i] = (1ll<<(i-1));
		for (int j=1; j<i; j++) if (i%j==0)
			dp[i]-=dp[j];
	}
	cin >> lo >> hi;
	cout << go(hi) - go(lo-1) << endl;
	return 0;
}