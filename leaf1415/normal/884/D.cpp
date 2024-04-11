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
ll a[200005];
priority_queue<ll, vector<ll>, greater<ll> > Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], Q.push(a[i]);
	
	ll ans = 0;
	while(Q.size() > 1){
		ll sum = 0, x = 3;
		if(Q.size() % 2 == 0) x = 2;
		rep(i, 1, x){
			sum += Q.top();
			Q.pop();
		}
		ans += sum;
		Q.push(sum);
	}
	cout << ans << endl;
	
	return 0;
}