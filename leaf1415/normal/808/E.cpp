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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, m;
vector<ll> vec[4], sum[4];

ll calc(ll x, ll m)
{
	ll ret = 0;
	if(x > 0) ret += sum[2][x-1];
	x = min((ll)vec[1].size(), m-2*x);
	if(x > 0) ret += sum[1][x-1];
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll w, c;
	rep(i, 1, n){
		cin >> w >> c;
		vec[w].push_back(c);
	}
	rep(i, 1, 3){
		sort(all(vec[i])), reverse(all(vec[i]));
		ll s = 0;
		reps(j, vec[i]){
			s += vec[i][j];
			sum[i].push_back(s);
		}
	}
	
	ll ans = 0, sum = 0;
	rep(i, 0, min(m/3, (ll)vec[3].size())){
		ll ub = min((ll)vec[2].size(), (m-3*i)/2), lb = 0, mid, mid2;
		while(ub-lb>4){
			mid = (ub+lb*2)/3, mid2 = (ub*2+lb)/3;
			if(calc(mid, m-3*i) >= calc(mid2, m-3*i)) ub = mid2;
			else lb = mid;
		}
		rep(j, lb, ub) chmax(ans, calc(j, m-3*i) + sum);
		if(i < vec[3].size()) sum += vec[3][i];
	}
	cout << ans << endl;
	
	return 0;
}