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
typedef pair<P, llint> E;

ll n, m;
set<P> S;
vector<E> ans;
bool prime[1000005];
vector<ll> pvec;

void add(ll u, ll v, ll w)
{
	if(u > v) swap(u, v);
	S.insert(P(u, v));
	ans.push_back(E(P(u, v), w));
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 2, 1005){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000005; j+=i) prime[j] = true;
	}
	rep(i, 2, 1000000) if(!prime[i]) pvec.push_back(i);
	
	cin >> n >> m;
	add(1, n, 2);
	rep(i, 2, n-2) add(1, i, 1);
	
	ll x = 2+(n-3);
	ll y = *upper_bound(all(pvec), x);
	if(n >= 3) add(1, n-1, y-x);
	
	rep(i, 1, n){
		rep(j, i+1, n){
			if(S.size() >= m) goto end;
			if(S.count(P(i, j))) continue;
			add(i, j, 1000000000);
		}
	}
	end:;
	
	cout << 2 << " " << y << endl;
	for(auto e : ans)
	{
		cout << e.first.first << " " << e.first.second << " " << e.second << endl;
	}
	
	return 0;
}