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

ll n[3];
vector<ll> vec[3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll sum = 0;
	rep(i, 0, 2) cin >> n[i];
	rep(i, 0, 2){
		ll x;
		rep(j, 1, n[i]){
			cin >> x;
			sum += x;
			vec[i].push_back(x);
		}
	}
	vector<ll> tmp;
	rep(i, 0, 2){
		sort(all(vec[i]));
		tmp.push_back(vec[i][0]);
		//if(n[i] >= 2) tmp.push_back(vec[i][1]);
	}
	sort(all(tmp));
	
	ll ans = sum - 2 * (tmp[0] + tmp[1]);
	rep(i, 0, 2){
		if(n[i] == 1) chmax(ans, sum - 2*vec[i][0]);
		if(n[i] == 2) chmax(ans, sum - 2*(vec[i][0] + vec[i][1]));
		ll s = 0;
		for(auto x : vec[i]) s += x;
		chmax(ans, sum - 2*s);
	}
	cout << ans << endl;
	
	return 0;
}