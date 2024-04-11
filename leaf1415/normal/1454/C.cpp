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
ll a[200005];
vector<ll> vec[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n){
			vec[i].clear();
			vec[i].push_back(0);
		}
		rep(i, 1, n){
			cin >> a[i];
			vec[a[i]].push_back(i);
		}
		rep(i, 1, n) vec[i].push_back(n+1);
		
		ll ans = inf;
		rep(i, 1, n){
			ll cnt = 0;
			if(vec[i].size() == 2) continue;
			rep(j, 1, (int)vec[i].size()-1){
				if(vec[i][j] - vec[i][j-1] > 1) cnt++;
			}
			chmin(ans, cnt);
		}
		cout << ans << endl;
	}
	
	return 0;
}