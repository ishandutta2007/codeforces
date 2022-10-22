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

ll n, T;
ll a[200005], t[200005];
vector<P> vec;

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> T;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> t[i], t[i] -= T;
	
	ll sum = 0;
	rep(i, 1, n) sum += t[i]*a[i];
	if(sum > 0){
		rep(i, 1, n) t[i] *= -1;
	}
	
	double ans = 0; sum = 0;
	rep(i, 1, n){
		if(t[i] >= 0) ans += a[i], sum += t[i]*a[i];
		else vec.push_back(P(-t[i], a[i]));
	}
	sort(all(vec));
	
	for(auto p : vec){
		ll t = p.first, a = p.second;
		if(sum >= t*a){
			ans += a, sum -= t*a;
		}
		else{
			ans += (double)sum / t;
			break;
		}
	}
	printf("%.11f\n", ans);
	
	return 0;
}