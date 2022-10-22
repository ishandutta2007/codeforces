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
vector<P> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		
		vector<ll> vec; set<ll> S;
		ll x = n;
		vec.push_back(n), S.insert(n);
		while(x >= 3){
			x = sqrt(x) + 1;
			vec.push_back(x), S.insert(x);
		}
		
		ans.clear();
		rep(i, 1, n){
			if(i >= 2 && S.count(i) == 0) ans.push_back(P(i, n));
		}
		rep(i, 0, (int)vec.size()-2){
			ans.push_back(P(vec[i], vec[i+1]));
			ans.push_back(P(vec[i], vec[i+1]));
		}
		cout << ans.size() << "\n";
		for(auto p : ans) cout << p.first << " " << p.second << "\n";
	}
	flush(cout);
	
	return 0;
}