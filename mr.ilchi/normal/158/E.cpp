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

const int maxN = 4000 + 10;

int n,k;
int dp[maxN][maxN];
vector <int> st,end,Q;
vector <pii> DP;

inline bool go (int sz){
	
	int poi=0;

	for (int s=1; s+sz-1<=86400; s++){
		int e = s+sz-1;
		while (poi<n && st[poi]<=e) poi++;
		int t1 = n-poi;
		if (t1>=n-k)
			return true;
		int t2 = (n-k-t1);
		if (dp[n-1][t2] < s)
			return true;
	}
	return false;
}

int main(){
	cin >> n >> k;
	for (int i=1; i<=n; i++){
		int s,d; cin >> s >> d;
		int e = s + d - 1;
		st.push_back (s);
		Q.push_back(e+1);
		DP.push_back(pii(s,e));
	}
	Q.push_back (1);
	sort (DP.begin(),DP.end());
	sort (st.begin(),st.end());
	sort (Q.begin(),Q.end());
	Q.resize(unique(Q.begin(),Q.end())-Q.begin());

	for (int i=0; i<(int)DP.size(); i++){
		for (int j=1; j<=n; j++){
			dp[i][j] = 86400; 
			if (i==0){
				if (j==1)
					dp[i][j] = DP[i].second;
				continue;
			}
			if (j==1)
				dp[i][j] = min(dp[i-1][j],DP[i].second);
			else
				dp[i][j] = min(dp[i-1][j],(dp[i-1][j-1]<DP[i].first) ? (DP[i].second) : (dp[i-1][j-1] + (DP[i].second-DP[i].first+1)));
		}
	}

	int s=1,e=86400,ans=0;

	while (s <= e){
		
		int mid = (s+e)/2;

		if (go(mid)){
			ans=mid , s=mid+1;
		}
		else
			e = mid-1;
	}

	cout << ans << endl;

	return 0;
}