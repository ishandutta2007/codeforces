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
#define mod 1000000007

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

ll T;
ll n;
ll l[200005], r[200005];
vector<ll> vec[500005], qvec[500005];

void make(ll x[], vector<ll> &comp)
{
	rep(i, 1, n) comp.push_back(x[i]);
	sort(all(comp));
	comp.erase(unique(all(comp)), comp.end());
	rep(i, 1, n) x[i] = lower_bound(all(comp), x[i]) - comp.begin() + 1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> l[i] >> r[i];
		
		vector<ll> comp;
		rep(i, 1, n) comp.push_back(l[i]), comp.push_back(r[i]);
		sort(all(comp));
		comp.erase(unique(all(comp)), comp.end());
		rep(i, 1, n){
			l[i] = lower_bound(all(comp), l[i]) - comp.begin() + 1;
			r[i] = lower_bound(all(comp), r[i]) - comp.begin() + 1;
		}
		
		BIT bit(2*n+10);
		rep(i, 1, 2*n+5) vec[i].clear(), qvec[i].clear();
		rep(i, 1, n) vec[l[i]].push_back(r[i]), qvec[r[i]].push_back(l[i]);
		
		ll ans = 0;
		rep(i, 1, 2*n+5){
			for(auto x : vec[i]) bit.add(x, 1);
			for(auto q : qvec[i]) chmax(ans, bit.query(2*n+5) - bit.query(q-1));//, cout << i << " "  << q << " " << ans << endl;
			
		}
		//cout << ans << endl;
		cout << n - ans << "\n";
	}
	flush(cout);
	
	return 0;
}