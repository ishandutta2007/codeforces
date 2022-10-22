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

ll n;
ll p[100005];
bool used[100005];
vector<ll> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> p[i];
	
	rep(i, 1, n){
		if(used[i]) continue;
		ll v = i, cnt = 0;
		while(!used[v]){
			used[v] = true;
			cnt++;
			v = p[v];
		}
		vec.push_back(cnt);
	}
	sort(all(vec));
	if(vec.size() >= 2){
		ll x = vec.back();
		vec.pop_back();
		vec.back() += x;
	}
	ll ans = 0;
	for(auto x : vec) ans += x*x;
	cout << ans << endl;
	
	return 0;
}