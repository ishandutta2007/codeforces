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

ll n, m, k;
vector<P> gvec[1000005], bvec[1000005];
ll gcost[1000005], bcost[1000005];
ll a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	ll d, f, t, c;
	rep(i, 1, m){
		cin >> d >> f >> t >> c;
		if(f == 0) bvec[d].push_back(P(t, c));
		else gvec[d].push_back(P(f, c));
	}
	
	ll sum = 0;
	rep(i, 1, n) a[i] = 1e12, sum += a[i];
	rep(i, 1, 1000000){
		for(auto p : gvec[i]){
			ll id = p.first, cost = p.second;
			if(a[id] > cost){
				sum -= a[id], sum += cost;
				a[id] = cost;
			}
		}
		gcost[i] = sum;
	}
	
	sum = 0;
	rep(i, 1, n) a[i] = 1e12, sum += a[i];
	for(int i = 1000000; i >= 1; i--){
		for(auto p : bvec[i]){
			ll id = p.first, cost = p.second;
			if(a[id] > cost){
				sum -= a[id], sum += cost;
				a[id] = cost;
			}
		}
		bcost[i] = sum;
	}
	
	ll ans = inf;
	rep(i, 2, 1000000){
		if(i+k > 1000000) break;
		chmin(ans, gcost[i-1] + bcost[i+k]);
	}
	if(ans >= 1e12) ans = -1;
	cout << ans << endl;
	
	
	return 0;
}