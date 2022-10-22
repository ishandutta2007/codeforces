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
vector<ll> vec, vec2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		vec.clear();
		ll x;
		rep(i, 1, n){
			cin >> x;
			vec.push_back(x);
		}
		vec2 = vec;
		reverse(all(vec2));
		
		vector<ll> ans;
		rep(i, 0, n-1) ans.push_back(vec[i]), ans.push_back(vec2[i]);
		rep(i, 0, n-1) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}