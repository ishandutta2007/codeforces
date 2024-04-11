#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
llint x[85], r[85];
llint dp[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> x[i] >> r[i];
	
	for(int i = 1; i <= m; i++) dp[i] = inf;
	for(llint i = 0; i < m; i++){
		for(int j = 1; j <= n; j++){
			if(x[j] > i){
				llint L = max(i+1, x[j]-r[j]), R = x[j]+r[j];
				llint dif = L - (i+1);
				llint nR = min(m, R + dif);
				chmin(dp[nR], dp[i] + dif);
			}
			else{
				llint R = min(m, x[j]+r[j]);
				if(R > i) chmin(dp[R], dp[i]);
			}
			if(x[j] > i){
				llint L = max(i+1, x[j]-r[j]), R = min(m, x[j]+r[j]);
				llint cost = max(L-(i+1), m-R);
				chmin(dp[m], dp[i] + cost);
			}
			else{
				llint R = max(i, min(m, x[j]+r[j]));
				llint cost = m-R;
				chmin(dp[m], dp[i] + cost);
			}
		}
	}
	
	//for(int i = 1; i <= m; i++) cout << dp[i] << " "; cout << endl;
	cout << dp[m] << endl;
	
	return 0;
}