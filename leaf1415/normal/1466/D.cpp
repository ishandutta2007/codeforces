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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll n;
ll w[100005];
vector<ll> G[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		
		ll ans = 0;
		rep(i, 1, n) cin >> w[i], ans += w[i];
		
		rep(i, 1, n) G[i].clear();
		ll u, v;
		rep(i, 1, n-1){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		priority_queue<ll> Q;
		rep(i, 1, n){
			rep(j, 1, (int)G[i].size()-1) Q.push(w[i]);
		}
		cout << ans << " ";
		rep(i, 1, n-2){
			ans += Q.top();
			Q.pop();
			cout << ans << " ";
		}
		cout << "\n";
	}
	flush(cout);
	
	return 0;
}