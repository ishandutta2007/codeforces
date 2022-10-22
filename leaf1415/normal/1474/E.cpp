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
ll p[200005];
vector<P> ans;

ll add(ll x, ll y)
{
	ans.push_back(P(y, x));
	swap(p[x], p[y]);
	return (x-y)*(x-y);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) p[i] = i;
		
		if(n == 1){
			cout << 0 << endl;
			cout << 1 << endl;
			cout << 0 << endl;
			continue;
		}
		
		ll cost = 0; ans.clear();
		cost += add(1, n);
		rep(i, n/2+1, n-1) cost += add(1, i);
		rep(i, 2, n/2) cost += add(n, i);
		reverse(all(ans));
		
		cout << cost << "\n";
		rep(i, 1, n) cout << p[i] << " "; cout << "\n";
		cout << ans.size() << "\n";
		for(auto p : ans) cout << p.first << " " << p.second << "\n";
		flush(cout);
		
		for(auto q : ans){
			ll i = q.first, j = q.second;
			assert(i != j && p[j] == i);
			swap(p[i], p[j]);
		}
		rep(i, 1, n) assert(p[i] == i);
	}
	flush(cout);
	
	return 0;
}