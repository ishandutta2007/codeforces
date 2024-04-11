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
ll a[3005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		
		ll ans = inf;
		rep(i, 1, n){
			ll sum = 0;
			rep(j, 1, i) sum += a[j];
			
			ll s = 0, cnt = 1;
			rep(j, i+1, n){
				s += a[j];
				if(s == sum) s = 0, cnt++;
				if(s > sum){
					cnt = -inf;
					break;
				}
			}
			if(s == sum) cnt++;
			else if(s != 0) cnt = -inf;
			chmin(ans, n - cnt);
		}
		cout << ans << endl;
	}
	
	return 0;
}