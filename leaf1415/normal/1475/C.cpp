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
ll x, y;
ll a[200005], b[200005];
ll A[200005], B[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> x >> y >> n;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) cin >> b[i];
		
		rep(i, 1, x) A[i] = 0;
		rep(i, 1, y) B[i] = 0;
		rep(i, 1, n) A[a[i]]++, B[b[i]]++;
		
		ll ans = 0;
		rep(i, 1, n){
			ans += n - (A[a[i]] + B[b[i]] - 1);
		}
		cout << ans/2 << endl;
	}
	
	return 0;
}