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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n;
llint a[10];
llint b[100005];
vector<llint> vec[100005];
multiset<P> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 1; i <= 6; i++) cin >> a[i];
	sort(a+1, a+7);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> b[i];
	sort(b+1, b+n+1);
	
	for(int i = 1; i <= n; i++){
		vec[i].push_back(inf);
		for(int j = 1; j <= 6; j++){
			vec[i].push_back(b[i]-a[j]);
		}
	}
	
	llint ans = inf;
	for(int i = 1; i <= n; i++) S.insert(P(vec[i].back(), i));
	
	while(1){
		if(S.begin()->first > inf/2) break;
		
		//for(auto x: S) cout << x.first << " " ; cout << endl;
		
		llint l = S.begin()->first, r = S.rbegin() -> first;
		ans = min(ans, r-l);
		
		llint id = S.begin()->second;
		S.erase(S.begin());
		vec[id].pop_back();
		S.insert(P(vec[id].back(), id));
	}
	cout << ans << endl;
	
	return 0;
}