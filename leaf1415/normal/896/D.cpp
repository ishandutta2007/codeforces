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


typedef pair<llint, llint> P;

map<llint, llint> mp;
llint a[55], b[55], m[55];
bool prime[40005];

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

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

llint mod_inverse(llint a, llint m)
{
	llint x, y;
	if(extgcd(a, m, x, y) != 1) return -1;
	return (x%m + m) % m;
}

P congruence(llint a, llint b, llint m)
{
	llint d = gcd(a, m);
	if(b % d) return make_pair(0, -1);
	a /= d, b /= d, m /= d;
	return make_pair(b * mod_inverse(a, m) % m, m);
}

P SimultaneousCongruence(llint a[], llint b[], llint m[], llint n)
{
	llint x = 0, M = 1;
	for(int i = 1; i <= n; i++){
		P res = congruence(a[i]*M, (b[i]-a[i]*x%m[i]+m[i])%m[i], m[i]);
		if(res.second == -1) return res;
		x += M*res.first, M *= res.second;
	}
	return make_pair(x, M);
}

const int FACT_MAX = 4000005;
llint q[FACT_MAX], e[FACT_MAX];

llint modpow(llint a, llint n, llint mod)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1, mod)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2, mod) % mod;
	}
}

void make_fact(llint p, llint mod)
{
	llint qval = 1, eval = 0;
	q[0] = 1, e[0] = 0;

	for(int i = 1; i < FACT_MAX; i++){
		llint t = i;
		while(t % p == 0){
			eval++;
			t /= p;
		}
		qval *= t, qval %= mod;
		q[i] = qval, e[i] = eval;
	}
}

llint comb(llint n, llint k, llint p, llint ex, llint mod)
{
	llint eval = e[n] - e[k] - e[n-k];
	if(eval >= ex) return 0;

	llint ret = q[n] * mod_inverse(q[k]*q[n-k]%mod, mod) % mod;
	ret *= modpow(p, eval, mod), ret %= mod;
	return ret;
}

ll n, M, l, r;

ll get(ll n, ll r, ll p, ll ex, ll mod)
{

	if(n % 2 != r % 2) r++;
	if(r > n) return 0;
	ll h = (n-r)/2;

	ll ret = comb(n, h, p, ex, mod);
	return ret;
}

llint calc(llint p, llint ex, llint mod)
{
	make_fact(p, mod);

	ll ret = 0;
	rep(i, 0, n){
		ll tmp = get(n-i, l, p, ex, mod) - get(n-i, r+1, p, ex, mod) + mod;
		tmp *= comb(n, i, p, ex, mod), tmp %= mod;
		ret += tmp, ret %= mod;
		//cout << i << " " << tmp << endl;
	}

	return ret;
}


int main(void)
{
	cin >> n >> M >> l >> r;

	for(int i = 2; i < 40005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 40005; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 40005; i++){
		if(prime[i]) continue;
		while(M%i == 0){
			mp[i]++;
			M /= i;
		}
	}
	if(M > 1) mp[M]++;

	llint id = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		id++;
		llint mod = 1;
		for(int i = 0; i < it->second; i++) mod *= it->first;
		a[id] = 1, b[id] = calc(it->first, it->second, mod), m[id] = mod;
	}
	cout << SimultaneousCongruence(a, b, m, id).first << endl;

	return 0;
}