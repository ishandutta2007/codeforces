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

llint T;
llint n, m;
llint a[105][105];
map<P, vector<llint> > mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}
		mp.clear();
		for(llint i = 1; i <= n; i++){
			for(llint j = 1; j <= m; j++){
				llint x = min(i, n+1-i), y = min(j, m+1-j);
				mp[P(x, y)].push_back(a[i][j]);
			}
		}
		llint ans = 0;
		for(auto it = mp.begin(); it != mp.end(); it++){
			vector<llint> &vec = it->second;
			sort(vec.begin(), vec.end());
			llint x = vec.size();
			for(int i = 0; i < vec.size(); i++) ans += abs(vec[i]-vec[x/2]);
		}
		cout << ans << endl;
	}
	
	return 0;
}