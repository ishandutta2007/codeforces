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
#define eps 1e-11

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

int gcd(int a, int b){
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

int n, m;
bool used[200005];
int dp[200005], rec[200005];
vector<int> vec[200005], rvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	int x;
	rep(i, 1, n) cin >> x, used[x] = true;
	rep(i, 1, m) if(!used[i%m]) vec[gcd(i, m)].push_back(i);
	
	rep(i, 1, m) dp[i] = -1e9;
	dp[1] = vec[1].size();
	rep(i, 1, m){
		if(m % i) continue;
		for(int j = 2*i; j <= m; j+=i){
			if(dp[j] < dp[i] + (int)vec[j].size()){
				dp[j] = dp[i] + (int)vec[j].size();
				rec[j] = i;
			}
		}
	}
	
	int p = m;
	while(1){
		for(auto x : vec[p]) rvec.push_back(x);
		if(p == 1) break;
		p = rec[p];
	}
	reverse(all(rvec));
	
	vector<int> ans; ll mul = 1;
	for(auto x : rvec){
		P res = congruence(mul, x, m);
		assert(res.second != -1);
		ans.push_back(res.first);
		mul *= res.first, mul %= m;
	}
	
	cout << ans.size() << endl;
	for(auto x : ans) cout << x << " "; cout << endl;
	
	return 0;
}