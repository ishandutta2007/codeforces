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
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<ll, string> Q;

ll n;
ll x[200005];
set<ll> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, 1, n) cin >> x[i], S.insert(x[i]);

	vector<ll> ans;
	rep(i, 1, n){
		rep(j, 0, 35){
			vector<ll> tmp;
			tmp.push_back(x[i]);
			if(S.count(x[i]+(1LL<<j))) tmp.push_back(x[i]+(1LL<<j));
			if(S.count(x[i]-(1LL<<j))) tmp.push_back(x[i]-(1LL<<j));
			if(ans.size() < tmp.size()) ans = tmp;
		}
	}
	cout << ans.size() << endl;
	for(auto x : ans) cout << x << " "; cout << endl;

	return 0;
}