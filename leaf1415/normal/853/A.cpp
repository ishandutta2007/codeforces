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

ll n, k;
ll c[300005];
ll a[300005];
priority_queue<P> Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> c[i];
	
	ll ans = 0;
	rep(i, 1, n) ans -= c[i] * i;
	rep(i, 1, n+k){
		if(i <= n) Q.push(P(c[i], i));
		if(i > k){
			ans += Q.top().first * i;
			a[Q.top().second] = i;
			Q.pop();
		}
	}
	cout << ans << endl;
	rep(i, 1, n) cout << a[i] << " "; cout << endl;
	
	return 0;
}