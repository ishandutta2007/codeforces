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
vector<P> vec;
ll ans[25];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll x;
	rep(i, 0, n-1){
		cin >> x;
		vec.push_back(P(x, i));
	}
	sort(all(vec));
	
	rep(i, 0, n-1) ans[vec[i].second] = vec[(i+1)%n].first;
	rep(i, 0, n-1) cout << ans[i] << " "; cout << endl;
	
	return 0;
}