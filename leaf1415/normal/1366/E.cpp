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
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
llint a[200005], b[200005];
vector<P> vec;
vector<llint> Mvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++){
		vec.push_back(P(a[i], i));
	}
	sort(vec.begin(), vec.end());
	
	if(vec.front().first < b[1]){
		cout << 0 << endl;
		return 0;
	}
	
	llint mx = 0;
	for(int i = 0; i < vec.size(); i++){
		mx = max(mx, vec[i].second);
		Mvec.push_back(mx);
	}
	
	llint ans = 1;
	for(int i = 1; i <= m-1; i++){
		if(lower_bound(vec.begin(), vec.end(), P(b[i], 0LL))->first != b[i]){
			cout << 0 << endl;
			return 0;
		}
		llint p = lower_bound(vec.begin(), vec.end(), P(b[i+1], 0LL)) - vec.begin();
		
		llint l = Mvec[p-1];
		p = upper_bound(vec.begin(), vec.end(), P(b[i+1], inf)) - vec.begin();
		llint r = vec[p-1].second-1;
		if(l > r){
			cout << 0 << endl;
			return 0;
		}
		ans *= (r-l+1),ans %= mod;
		//cout << i << " " << l << " " << r << endl;
	}
	if(lower_bound(vec.begin(), vec.end(), P(b[m], 0LL))->first != b[m]){
		cout << 0 << endl;
		return 0;
	}
	cout << ans << endl;
	
	return 0;
}