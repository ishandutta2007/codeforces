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
typedef pair<P, llint> T;

ll Q;
ll n;
ll h[200005], w[200005];
ll ans[200005];
vector<T> vec;
set<P> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	while(Q--){
		cin >> n;
		rep(i, 1, n) cin >> h[i] >> w[i];
		
		vec.clear();
		rep(i, 1, n){
			vec.push_back(T(P(w[i], -h[i]), i));
			vec.push_back(T(P(h[i], -w[i]), -i));
		}
		sort(all(vec));
		
		S.clear();
		for(auto t : vec)
		{
			ll w = t.first.first, h = -t.first.second, id = t.second;
			if(id > 0){
				ans[id] = -1;
				for(auto p : S){
					if(p.first >= h) break;
					if(p.second != id){
						ans[id] = p.second;
						break;
					}
				}
			}
			S.insert(P(h, abs(id)));
		}
		rep(i, 1, n) cout << ans[i] << " ";  cout << endl;
	}
	
	return 0;
}