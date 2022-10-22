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
#define inf 1e9

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, k;
ll a[205];
ll b[205], c[205];
ll dp[2][205][5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n){
		cin >> a[i];
		while(a[i] % 2 == 0) b[i]++, a[i] /= 2;
		while(a[i] % 5 == 0) c[i]++, a[i] /= 5;
	}
	
	rep(j, 0, k) rep(l, 0, 5000) dp[0][j][l] = -inf;
	dp[0][0][0] = 0;
	
	rep(i, 0, n-1){
		rep(j, 0, k) rep(l, 0, 5000) dp[(i+1)&1][j][l] = -inf;
		rep(j, 0, k){
			rep(l, 0, 5000){
				chmax(dp[(i+1)&1][j][l], dp[i&1][j][l]);
				if(j+1 <= k && l+c[i+1] <= 5000){
					chmax(dp[(i+1)&1][j+1][l+c[i+1]], dp[i&1][j][l] + b[i+1]);
				}
			}
		}
	}
	ll ans = 0;
	rep(i, 0, 5000) chmax(ans, min(dp[n%2][k][i], i));
	cout << ans << endl;
	
	return 0;
}