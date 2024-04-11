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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

llint n, Q;
bool prime[40000005];
vector<llint> vec;
map<llint, llint> mp, mp2, mp3;

const int FACT_MAX = 20005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

void get(llint x, map<llint, llint> &mp)
{
	mp.clear();
	for(int i = 0; i < vec.size(); i++){
		llint p = vec[i];
		while(x%p == 0){
			x /= p;
			mp[p]++;
		}
	}
}

llint calc(map<llint, llint> &mp, map<llint, llint> &mp2)
{
	llint sum = 0, ret = 1;
	for(auto it = mp.begin(); it != mp.end(); it++){
		llint dif = it->second - mp2[it->first];
		ret *= fact_inv[dif], ret %= mod;
		sum += dif;
	}
	ret *= fact[sum], ret %= mod;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	for(int i = 2; i < 7005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 40000005; j+=i) prime[j] = true;
	}
	
	cin >> n >> Q;
	for(int i = 2; i < 40000005; i++){
		while(n%i == 0){
			n /= i;
			vec.push_back(i);
		}
	}
	if(n > 1) vec.push_back(n);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	
	llint u, v;
	for(int q = 0; q < Q; q++){
		cin >> u >> v;
		llint g = gcd(u, v);
		get(u, mp), get(v, mp2), get(g, mp3);
		
		llint ans = calc(mp, mp3) * calc(mp2, mp3) % mod;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}