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
ll a[100005];
ll sum[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	a[n+1] = inf;
	
	rep(i, 1, n-1){
		if(a[i-1] > (a[i]^a[i+1]) || (a[i]^a[i+1]) > a[i+2]){
			cout << 1 << endl;
			return 0;
		}
	}
	rep(i, 1, n) sum[i] = sum[i-1] ^ a[i];
	
	ll ans = inf;
	rep(i, 1, n){
		rep(j, 1, n){
			rep(k, 1, n){
				if(i+j+k-1 > n) continue;
				if((sum[i+j-1]^sum[i-1]) > (sum[i+j+k-1]^sum[i+j-1])) chmin(ans, j-1+k-1);
			}
		}
	}
	if(ans > inf/2) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}