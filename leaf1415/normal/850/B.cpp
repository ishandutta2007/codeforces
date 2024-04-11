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

ll n, x, y;
ll a[500005];
ll c[2000005];
ll nsum[2000005], wsum[2000005];
vector<ll> pvec;
bool prime[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 2, 1000){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000005; j+=i) prime[j] = true;
	}
	rep(i, 2, 1000000) if(!prime[i]) pvec.push_back(i);
	
	cin >> n >> x >> y;
	rep(i, 1, n) cin >> a[i], c[a[i]]++;
	rep(i, 1, 2000000) nsum[i] = nsum[i-1] + c[i], wsum[i] = wsum[i-1] + c[i]*i;
	
	ll ans = inf;
	for(auto p : pvec)
	{
		ll sum = 0, d = min(p, (x+y-1)/y);
		for(int i = p; i <= 1000000+p; i += p){
			sum += (nsum[i-d] - nsum[i-p]) * x;
			sum += (i * (nsum[i] - nsum[i-d]) - (wsum[i] - wsum[i-d])) * y;
		}
		chmin(ans, sum);
	}
	cout << ans << endl;
	
	return 0;
}