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
typedef pair<int, int> P;

int T;
int n;
int a[200005];
vector<int> vec[205];
vector<P> tmp;
int dp[200005][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		for(int i = 1; i <= 200; i++) vec[i].clear();
		for(int i = 1; i <= n; i++) vec[a[i]].push_back(i);
		
		int ans = 0;
		for(int i = 1; i <= 200; i++) ans = max(ans, (int)vec[i].size());
		for(int i = 1; i <= 200; i++){
			for(int j = 1; j <= 200; j++){
				if(i == j) continue;
				for(int k = 1; k <= (int)vec[i].size(); k++){
					int l = vec[i][k-1]+1;
					int r = vec[i][(int)vec[i].size()-k]-1;
					if(l > r) break;
					int x = upper_bound(vec[j].begin(), vec[j].end(), r) - lower_bound(vec[j].begin(), vec[j].end(), l);
					ans = max(ans, 2*k+x);
				}
			}
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}