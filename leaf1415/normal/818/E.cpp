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

ll n, k;
ll a[100005];
bool prime[100005];
map<ll, ll> kmp, mp;

void add(ll x, ll m)
{
	for(auto p : kmp){
		while(x % p.first == 0) mp[p.first] += m, x /= p.first;
	}
}
bool check()
{
	for(auto p : kmp){
		if(mp[p.first] < p.second) return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 2, 100000){
		if(prime[i]) continue;
		for(int j = 2*i; j < 100005; j+=i) prime[j] = true;
	}
	
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i];
	
	if(k == 1){
		cout << n*(n+1)/2 << endl;
		return 0;
	}
	
	rep(i, 2, 100000){
		if(prime[i]) continue;
		while(k % i == 0) kmp[i]++, k /= i;
	}
	if(k > 1) kmp[k]++;
	
	ll ans = 0, r = 0;
	rep(l, 1, n){
		while(r < n && !check()) r++, add(a[r], 1);
		if(check()) ans += n-r+1;
		add(a[l], -1);
	}
	cout << ans << endl;
	
	return 0;
}