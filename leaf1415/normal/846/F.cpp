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
ll a[1000005];
vector<ll> vec[1000005];

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], vec[a[i]].push_back(i);
	rep(i, 1, 1000000) vec[i].insert(vec[i].begin(), 0), vec[i].push_back(n+1);
	
	ll ans = 0;
	rep(i, 1, 1000000){
		rep(j, 1, (int)vec[i].size()-2){
			ll x = (vec[i][j] - vec[i][j-1]) * (n+1 - vec[i][j]);
			x = (x - 1) * 2 + 1;
			ans += x;
		}
	}
	printf("%.11f\n", (double)ans/(n*n));
	
	return 0;
}