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

llint n, k;
llint a[200005], c[200005];
llint pos[200005];
vector<llint> vec;
set<P> S;
vector<llint> ans[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	
	for(int i = 1; i <= k; i++) cin >> c[i];
	for(int i = k; i >= 1; i--){
		for(int j = 0; j < c[i]-c[i+1]; j++) vec.push_back(i);
	}
	reverse(vec.begin(), vec.end());
	
	//for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;
	
	for(int i = 1; i <= k; i++) pos[i] = lower_bound(vec.begin(), vec.end(), i) - vec.begin();
	
	llint id = 0;
	for(int i = 1; i <= n; i++){
		llint p = pos[a[i]];
		auto it = S.lower_bound(P(p, -inf));
		if(it == S.end()){
			id++;
			S.insert(P(c[1]-1, id));
			it = S.lower_bound(P(p, -inf));
		}
		P tmp = *it;
		ans[tmp.second].push_back(a[i]);
		S.erase(it);
		tmp.first--;
		if(tmp.first >= 0) S.insert(tmp);
	}
	
	cout << id << endl;
	for(int i = 1; i <= id; i++){
		cout << ans[i].size() << " ";
		for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " "; cout << endl;
	}
	
	return 0;
}