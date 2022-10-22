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
#define PI 3.141592653589793238

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, k;
llint a[80], b[80];
llint dp[80][80], rec[80][80];
P p[80];
bool used[80];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> a[i] >> b[i];
			p[i] = P(b[i], i);
		}
		sort(p+1, p+n+1);
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= k; j++){
				dp[i][j] = -inf;
			}
		}
		dp[0][0] = 0;
		for(int i = 0; i < n; i++){
			llint id = p[i+1].second;
			for(int j = 0; j <= k; j++){
				
				if(dp[i+1][j] < dp[i][j] + b[id]*(k-1)){
					dp[i+1][j] = dp[i][j] + b[id]*(k-1);
					rec[i+1][j] = 0;
				}
				if(j < k){
					if(dp[i+1][j+1] < dp[i][j]+a[id]+b[id]*j){
						dp[i+1][j+1] = dp[i][j]+a[id]+b[id]*j;
						rec[i+1][j+1] = id;
					}
				}
			}
		}
		
		llint j = k;
		vector<llint> tmp;
		for(int i = n; i >= 1; i--){
			if(rec[i][j] == 0) continue;
			tmp.push_back(rec[i][j]);
			j--;
		}
		reverse(tmp.begin(), tmp.end());
		
		vector<llint> ans;
		for(int i = 1; i <= n; i++) used[i] = false;
		for(int i = 0; i < k; i++) used[tmp[i]] = true;
		for(int i = 0; i < k-1; i++) ans.push_back(tmp[i]);
		for(int i = 1; i <= n; i++){
			if(!used[i]) ans.push_back(i), ans.push_back(-i);
		}
		ans.push_back(tmp[k-1]);
		
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}