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

ll n, m;
ll a[40];
vector<ll> vec, vec2;

void calc(ll b, ll n, vector<ll> &vec)
{
	ll N = 1<<n;
	rep(i, 0, N-1){
		ll sum = 0;
		rep(j, 0, n-1){
			if(i & (1<<j)) sum += a[b+j];
		}
		vec.push_back(sum%m);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	rep(i, 0, n-1) cin >> a[i];

	if(m == 1){
		cout << 0 << endl;
		return 0;
	}
	if(n == 1){
		cout << a[0]%m << endl;
		return 0;
	}

	calc(0, n/2, vec);
	calc(n/2, n-n/2, vec2);
	sort(all(vec2));

	ll ans = 0;
	for(auto x : vec)
	{
		ll p = upper_bound(all(vec2), m-1-x) - vec2.begin() - 1;
		if(p >= 0){
			chmax(ans, (x + vec2[p]) % m);
			continue;
		}
		chmax(ans, (x + vec2.back()) % m);
	}
	cout << ans << endl;

	return 0;
}