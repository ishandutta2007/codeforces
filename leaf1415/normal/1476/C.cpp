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
ll c[100005];
ll a[100005], b[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> c[i];
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) cin >> b[i];
		rep(i, 1, n) if(a[i] > b[i]) swap(a[i], b[i]);
		
		ll ans = 0, len = b[2]-a[2];
		rep(i, 2, n-1){
			len += 2 + c[i] - 1;
			chmax(ans, len);
			len -= b[i+1] - a[i+1];
			chmax(len, b[i+1]-a[i+1]);
			//cout << i << " " << len << endl;
			if(a[i+1] == b[i+1]) chmax(ans, len), len = 0;
		}
		len += 2 + c[n] - 1;
		chmax(ans, len);
		
		cout << ans << endl;
	}
	
	return 0;
}