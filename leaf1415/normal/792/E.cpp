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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 


typedef pair<llint, llint> P;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

//ax+by = gcd(a, b)(x, y)gcd(a, b)
llint extgcd(llint a, llint b, llint &x, llint &y)
{
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	llint xx, yy;
	llint d = extgcd(b, a%b, xx, yy);
	x = yy, y = xx-(a/b)*yy;
	return d;
}

//a^{-1} (mod m)(gcd(a, m)!=1)-1
llint mod_inverse(llint a, llint m)
{
	llint x, y;
	if(extgcd(a, m, x, y) != 1) return -1;
	return (x%m + m) % m;
}

//ax = b (mod m)x(mod m/gcd(a, m))(b%gcd(a, m)!=0)(0, -1)
P congruence(llint a, llint b, llint m)
{
	llint d = gcd(a, m);
	if(b % d) return make_pair(0, -1);
	a /= d, b /= d, m /= d;
	return make_pair(b * mod_inverse(a, m) % m, m);
}


ll n;
ll a[505];
set<ll> S;
vector<ll> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	sort(a+1, a+n+1);
	
	ll r = sqrt(a[1]);
	rep(i, 1, r+5) S.insert(i), S.insert(ceildiv(a[1],i));
	S.erase(0), S.erase(1), S.insert(a[1]+1);
	
	for(auto x : S) vec.push_back(x);
	reverse(all(vec));
	
	ll ans = 0;
	rep(i, 1, n) ans += a[i];
	
	for(auto h : vec){
		ll sum = 0; bool flag = true;
		rep(i, 1, n){
			ll x = congruence(h-1, a[i], h).first;
			if(h-1 > a[i] || a[i] < x*(h-1)){
				flag = false;
				break;
			}
			sum += (a[i] - x*(h-1)) / h + x;
		}
		if(flag){
			cout << sum << endl;
			return 0;
		}
	}
	end:;
	cout << ans << endl;
	
	return 0;
}