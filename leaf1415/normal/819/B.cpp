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

typedef long long ll;
typedef long long llint;
typedef pair<llint, llint> P;

ll n;
ll p[1000005];
ll cnt[4000005];
ll zero = 2000002;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, 1, n) cin >> p[i], p[i] = i - p[i], cnt[p[i]+zero]++;

	ll sum = 0, plus = 0;
	rep(i, 1, n){
		sum += abs(p[i]);
		if(p[i] >= 0) plus++;
	}
	ll ans = sum, ans_k = 0;
	rep(k, 1, n-1){
		sum += plus, sum -= n - plus;
		plus += cnt[zero-k];

		//cout << k << " " << sum << endl;

		ll pos = n+1-k;
		cnt[zero+p[pos]]--;
		sum -= abs(p[pos]+k), plus--;

		p[pos] -= n;

		cnt[zero+p[pos]]++;
		sum += abs(p[pos]+k);
		if(p[pos]+k >= 0) plus++;

		if(ans > sum) ans = sum, ans_k = k;

		//cout << k << " " << sum << endl;
	}
	cout << ans << " " << ans_k << endl;

	return 0;
}