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

const string DNA = "ACGT";
const int mod = 1000000009;

int n,m;
int good[110];
int nex [110][4];
int dp[1010][12][110];
map <string, int> mp;

int go (int pos, int rem, int past){
	if (rem==10)
		return 0;
	int &ret = dp[pos][rem][past];
	if (ret!=-1)
		return ret;
	if (pos==n+1)
		return ret = (rem==0);
	ret = 0;
	for (int j=0; j<4; j++){
		int cur = nex[past][j];
		ret+= go(pos+1, (good[cur]>rem) ? (0) : (rem+1), cur); ret%=mod;
	}
	return ret;
}

int main(){
	cin >> n >> m;
	mp[""] = 0;
	for (int i=1; i<=m; i++){
		string s; cin >> s;
		for (int j=0; j<(int)s.size(); j++){
			string cur = s.substr(0,j+1);
			if (mp.find(cur)==mp.end()){
				int sz = mp.size();
				mp[cur] = sz;
			}
		}
		good[mp[s]] = (int)s.size();
	}
	for (map<string,int> :: iterator it = mp.begin(); it!=mp.end(); it++){
		for (int j=0; j<4; j++){
			string tmp = (it->first) + DNA[j];
			while (mp.find(tmp)==mp.end())
				tmp.erase(tmp.begin());
			nex[(it->second)][j] = mp[tmp];
		}
		string cur = (it->first);
		while (!cur.empty()){
			cur.erase(cur.begin());
			if (mp.find(cur)!=mp.end())
				good[(it->second)] = max(good[(it->second)], good[mp[cur]]);
		}
	}
	memset(dp,-1,sizeof dp);
	cout << go(1,0,0) << endl;
	return 0;
}