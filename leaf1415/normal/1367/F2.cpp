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
llint a[200005];
vector<llint> comp;
vector<llint> vec[200005];
bool inc[200005];

llint calc(llint sum, llint l, llint r)
{
	//cout << sum << " " << l << " " << r << endl;
	if(l > r) return 0;
	llint ret = sum;
	if(l > 0) ret += lower_bound(vec[l-1].begin(), vec[l-1].end(), vec[l].front()) - vec[l-1].begin();
	if(r+1 < m) ret += vec[r+1].end() - lower_bound(vec[r+1].begin(), vec[r+1].end(), vec[r].back());
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		
		comp.clear();
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			comp.push_back(a[i]);
		}
		sort(comp.begin(), comp.end());
		comp.erase(unique(comp.begin(), comp.end()), comp.end());
		for(int i = 1; i <= n; i++) a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
		m = comp.size();
		
		for(int i = 0; i < m; i++) vec[i].clear();
		for(int i = 1; i <= n; i++) vec[a[i]].push_back(i);
		
		llint ans = 0;
		for(int i = 0; i < m; i++){
			ans = max(ans, (llint)vec[i].size());
			inc[i] = true;
			for(int j = 1; j < vec[i].size(); j++){
				if(vec[i][j] < vec[i][j-1]) inc[i] = false;
			}
		}
		
		for(int i = 1; i < m; i++){
			vector<llint> &avec = vec[i-1], &bvec = vec[i];
			for(int j = 0; j < avec.size(); j++){
				llint tmp = (j+1) + bvec.end() - lower_bound(bvec.begin(), bvec.end(), avec[j]);
				ans = max(ans, tmp);
			}
		}
		
		llint sum = 0, l = inf; bool flag = false;
		for(int i = 0; i < m; i++){
			if(inc[i]){
				if(!flag) flag = true, l = i, sum += vec[i].size();
				else{
					if(vec[i-1].back() <= vec[i].front()) sum += vec[i].size();
					else ans = max(ans, calc(sum, l, i-1)), l = i, sum = vec[i].size();
				}
			}else{
				ans = max(ans, calc(sum, l, i-1));
				flag = false;
			}
		}
		ans = max(ans, calc(sum, l, m-1));
		
		cout << n-ans << endl;
	}
	
	return 0;
}