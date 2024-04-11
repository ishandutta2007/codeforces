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
typedef pair<llint, P> T;

ll n, w, h;
ll g[100005], p[100005], t[100005];
map<ll, vector<P> > mp;
P ans[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> w >> h;
	rep(i, 1, n){
		cin >> g[i] >> p[i] >> t[i];
		ll d = p[i] + t[i];
		if(g[i] == 2) d *= -1;
		mp[p[i] - t[i]].push_back(P(d, i));
	}
	for(auto z : mp){
		vector<P> &vec = z.second;
		sort(all(vec));
		
		vector<T> gvec;
		for(auto v : vec){
			ll id = v.second;
			if(g[id] == 1) gvec.push_back(T(p[id]-h, P(p[id], h)));
			else gvec.push_back(T(w-p[id], P(w, p[id])));
		}
		sort(all(gvec));
		
		rep(i, 0, (int)vec.size()-1) ans[vec[i].second] = gvec[i].second;
	}
	
	rep(i, 1, n) cout << ans[i].first << " " << ans[i].second << endl;
	
	return 0;
}