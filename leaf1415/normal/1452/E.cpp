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
#define mod 998244353

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

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


ll n, m, k;
ll l[2005], r[2005];
P p[2005];
ll d[2005];

ll calc(ll L, ll R)
{
	rep(i, 1, n) d[i] = 0;
	rep(i, L, R) d[l[p[i].second]]++, d[r[p[i].second]+1]--;
	rep(i, 1, n) d[i] += d[i-1];
	rep(i, 1, n) d[i] += d[i-1];
	
	ll ret = 0;
	rep(i, 1, n-k+1) chmax(ret, d[i+k-1]-d[i-1]);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	rep(i, 1, m) cin >> l[i] >> r[i], p[i] = P(l[i]+r[i], i);
	sort(p+1, p+m+1);
	
	ll ans = 0;
	rep(i, 1, m){
		chmax(ans, calc(1, i) + calc(i+1, m));
	}
	cout << ans << endl;
	
	return 0;
}