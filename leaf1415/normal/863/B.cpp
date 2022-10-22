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
ll w[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	n *= 2;
	rep(i, 1, n) cin >> w[i];
	sort(w+1, w+n+1);
	
	ll ans = inf;
	rep(i, 1, n){
		rep(j, 1, n){
			if(i == j) continue;
			
			vector<ll> vec;
			rep(k, 1, n){
				if(k == i || k == j) continue;
				vec.push_back(w[k]);
			}
			ll sum = 0;
			rep(k, 0, (int)vec.size()-1){
				if(k % 2) sum += vec[k] - vec[k-1];
			}
			chmin(ans, sum);
		}
	}
	cout << ans << endl;
	
	return 0;
}