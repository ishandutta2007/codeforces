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
ll b[30];
ll l[30][200005], r[30][200005];
vector<P> vec;
set<ll> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	rep(j, 0, 29) b[j] = 0;
	rep(i, 1, n){
		rep(j, 0, 29){
			l[j][i] = b[j];
			if(a[i] & (1<<j)) b[j] = i;
		}
	}
	rep(j, 0, 29) b[j] = n+1;
	for(int i = n; i >= 1; i--){
		rep(j, 0, 29){
			r[j][i] = b[j];
			if(a[i] & (1<<j)) b[j] = i;
		}
	}
	
	rep(i, 1, n) vec.push_back(P(a[i], i));
	sort(all(vec));
	reverse(all(vec));
	S.insert(0), S.insert(n+1);
	
	ll ans = 0;
	for(auto p : vec)
	{
		ll x = p.first, pos = p.second;
		auto it = S.lower_bound(pos);
		ll R = *it-1; it--;
		ll L = *it+1;
		
		ll LL = L-1, RR = R+1;
		rep(j, 0, 29){
			if(x & (1<<j)) continue;
			chmax(LL, l[j][pos]);
			chmin(RR, r[j][pos]);
		}
		ll tmp = (pos-L+1) * (R-pos+1);
		tmp -= (pos-LL) * (RR-pos);
		ans += tmp;
		
		//cout << pos << " " << L << " " << LL << " " << RR << " " << R << " " << ans << endl;
		S.insert(pos);
	}
	cout << ans << endl;
	
	return 0;
}