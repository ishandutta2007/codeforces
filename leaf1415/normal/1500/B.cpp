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
#define sz(x) ((ll)(x).size())
#define ceil(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(...) dump_func(__VA_ARGS__)
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<ll, ll> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;}

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){
		to = a, cost = b;
	}
};

template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for(int i = 0; i<vec.size(); i++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U>& pair_var) {
	os << "(" << pair_var.first << ", " << pair_var.second << ")";
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
	for(typename map<T, U>::iterator itr = map_var.begin(); itr != map_var.end(); itr++) {
		os << "(" << itr->first << ", " << itr->second << ")";
		itr++;
		if(itr != map_var.end()) os << ",";
		itr--;
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
	for(typename set<T>::iterator itr = set_var.begin(); itr != set_var.end(); itr++) {
		os << *itr;
		++itr;
		if(itr != set_var.end()) os << " ";
		itr--;
	}
	return os;
}
void dump_func() {cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    cout << head;
    if(sizeof...(Tail) > 0) cout << " ";
    dump_func(std::move(tail)...);
}



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

//a_i*x = b_i (mod m_i)(i = 1, 2, ..., n)(x, M)(0, -1)
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

ll n, m, k, c;
ll a[500005], b[500005];
ll p[1000005], q[1000005];
P res[1000005];

bool check(ll x)
{
	ll sum = 0;
	rep(i, 1, c){
		if(res[i].second == -1) continue;
		sum += x / res[i].second;
		if(res[i].first < x % res[i].second) sum++;
	}
	//outl(x, x-sum);
	return x - sum >= k;
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, m) cin >> b[i];
	
	rep(i, 1, n) p[a[i]] = i;
	rep(i, 1, m) q[b[i]] = i;
	
	ll a[] = {0, 1, 1}, M[] = {0, n, m};
	c = 2*max(n, m);
	rep(i, 1, c){
		if(p[i] == 0 || q[i] == 0){
			res[i].second = -1;
			continue;
		}
		ll b[] = {0, p[i]%n-1, q[i]%m-1};
		res[i] = SimultaneousCongruence(a, b, M, 2);
	}
	
	ll ub = 1e18, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	outl(ub);
	
	return 0;
}