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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<ll, string> Q;

ll L, n, m;
ll a[2005];
bool used[2005];
ll dp[2005][2005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> n >> m;
	ll l, r;
	rep(i, 1, n){
		cin >> l >> r;
		rep(j, l+1, r) used[j] = true;
	}
	ll x, p;
	rep(i, 1, m){
		cin >> x >> p;
		if(a[x] > 0) chmin(a[x], p);
		else a[x] = p;
	}

	rep(i, 0, L){
		rep(j, 0, L+1){
			dp[i][j] = inf;
		}
	}
	dp[0][L+1] = 0;
	if(a[0]) dp[0][0] = 0;

	rep(i, 0, L-1){
		rep(j, 0, L+1){
			if(used[i+1] && j == L+1) continue;
			chmin(dp[i+1][L+1], dp[i][j] + a[j]);
			if(a[i+1]) chmin(dp[i+1][i+1], dp[i][j] + a[j]);
			chmin(dp[i+1][j], dp[i][j] + a[j]);
		}
	}

	ll ans = inf;
	rep(j, 0, L+1) chmin(ans, dp[L][j]);
	if(ans > inf/2) ans = -1;
	cout << ans << endl;

	return 0;
}