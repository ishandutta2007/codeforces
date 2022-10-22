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

ll n, Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	ll l = -1;
	for(;n;n/=2) l++;
	
	ll v; string s;
	rep(q, 1, Q){
		cin >> v >> s;
		ll p;
		rep(i, 0, inf){
			if(v & (1LL<<i)){
				p = i;
				break;
			}
		}
		v &= ~(1LL<<p);
		
		for(auto c : s){
			if(c == 'L' && p > 0) p--;
			if(c == 'R' && p > 0) v |= (1LL<<p), p--;
			if(c == 'U' && p < l) p++, v &= ~(1LL<<p);
		}
		v |= (1LL<<p);

		cout << v << "\n";
	}
	flush(cout);
	
	return 0;
}