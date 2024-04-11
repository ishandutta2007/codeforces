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
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxN = 2*1000*1000 + 5;
const int inf = 1000*1000*1000;

int n;
int dp[maxN][3],par[maxN][3];
string s;

inline void go (int pos , int b){

	if (pos==0){

		int bb = (b+2)/2;

		if (dp[pos][bb]==0)
			return;
		if (bb==1)
			cout << "+2^0" << endl;
		else
			cout << "-2^0" << endl;
		return;
	}	

	b+= (s[pos]=='1');

	int bb = (b+2)/2;

	int p = par[pos][bb];

	if (p == 2*b)
		go (pos-1 , p);

	else if (p < 2*b){
		cout << "+2^" << pos << endl;
		go (pos-1 , p);
	}

	else{
		cout << "-2^" << pos << endl;
		go (pos-1 , p);
	}
}

inline int ABS (int x){
	
	return max(x,-x);
}

int main(){
	
	cin >> s; reverse (s.begin(),s.end());

	n = (int)s.size(); s.resize(maxN,0);

	if (s[0]=='0'){		
		dp[0][0] = inf;
		dp[0][1] = 0;
		dp[0][2] = inf;
	}

	else{
		dp[0][0] = 1;
		dp[0][1] = 1;
		dp[0][2] = inf;
	}

	for (int i=1; i<maxN; i++){
		for (int j=-2; j<=2; j+=2){
			int ret = inf , now = j+(s[i]=='1');
			for (int z=-1; z<=1; z++) if (ABS(2 * (now-z)) < 3){
				int tmp = dp[i-1][(2*(now-z)+2)/2] + (z!=0);
				if (tmp < ret){
					ret = tmp;
					par[i][(j+2)/2] = 2 * (now-z);
				}
			}
			dp[i][(j+2)/2] = ret;
		}	
	}

	int ans = n-1;

	for (int i=n; i<maxN; i++) if (dp[i][1] < dp[ans][1])
		ans = i;

	cout << dp[ans][1] << endl;

	go (ans,0);

	return 0;
}