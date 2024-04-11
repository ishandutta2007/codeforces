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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
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

ll n, w;
P p[105];
ll ans[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> w;
	rep(i, 1, n) cin >> p[i].first, p[i].second = i;
	sort(p+1, p+n+1);
	
	rep(i, 1, n){
		ll y = (p[i].first+1)/2;
		if(y > w || y > p[i].first){
			cout << -1 << endl;
			return 0;
		}
		ans[p[i].second] = y;
		w -= y;
	}
	for(int i = n; i >= 1; i--){
		if(w <= 0) break;
		ll x = min(w, p[i].first - ans[p[i].second]);
		ans[p[i].second] += x;
		w -= x;
	}
	
	rep(i, 1, n) cout << ans[i] << " "; cout << endl;
	
	return 0;
}