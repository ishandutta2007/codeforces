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
typedef pair<P, ll> T;

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

ll n, Q;
ll p[200005], q[200005];
ll ans[200005];
vector<T> dvec[200005], uvec[200005];
BIT bit(200005);

ll get(ll x)
{
	return x*(x-1)/2;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	rep(i, 1, n) cin >> p[i];
	rep(i, 1, n) q[p[i]] = i;
	
	ll l, d, r, u;
	rep(i, 1, Q){
		cin >> d >> l >> u >> r;
		ans[i] += get(n) - (get(d-1) + get(n-u) + get(l-1) + get(n-r));
		dvec[l-1].push_back(T(P(1, d-1), i));
		dvec[l-1].push_back(T(P(u+1, n), i));
		uvec[r+1].push_back(T(P(1, d-1), i));
		uvec[r+1].push_back(T(P(u+1, n), i));
	}
	
	bit.init();
	rep(i, 1, n){
		bit.add(q[i], 1);
		for(auto t : dvec[i]){
			ll l = t.first.first, r = t.first.second, id = t.second;
			if(l > r) continue;
			ans[id] += get(bit.query(r) - bit.query(l-1));
		}
	}
	
	bit.init();
	for(int i = n; i >= 1; i--){
		bit.add(q[i], 1);
		for(auto t : uvec[i]){
			ll l = t.first.first, r = t.first.second, id = t.second;
			if(l > r) continue;
			ans[id] += get(bit.query(r) - bit.query(l-1));
		}
	}
	
	rep(i, 1, Q) cout << ans[i] << "\n";
	flush(cout);
	
	return 0;
}