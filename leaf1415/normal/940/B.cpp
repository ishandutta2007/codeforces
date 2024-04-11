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

ll n, k, a, b;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> a >> b;
	if(k == 1){
		cout << (n-1)*a << endl;
		return 0;
	}
	ll ans = 0;
	while(n > 1){
		if(n % k == 0){
			ans += min((n-n/k)*a, b);
			n /= k;
		}
		else {
			if(n < k) ans += (n-1)*a, n = 1;
			else ans += (n % k)*a, n -= n % k;
		}
	}
	cout << ans << endl;

	return 0;
}