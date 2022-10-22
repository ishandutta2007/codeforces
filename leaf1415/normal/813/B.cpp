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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll x, y, l, r;
vector<ll> xvec, yvec;
vector<ll> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x >> y >> l >> r;
	
	ll mul = 1, U = (ll)1e18+5;
	while(1){
		xvec.push_back(mul);
		if(mul >= (U+x-1)/x) break;
		mul *= x;
	}
	mul = 1;
	while(1){
		yvec.push_back(mul);
		if(mul >= (U+y-1)/y) break;
		mul *= y;
	}
	
	for(auto x : xvec) for(auto y : yvec) vec.push_back(x+y);
	vec.push_back(-inf), vec.push_back(3*inf);
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	
	ll ans = 0;
	rep(i, 0, (int)vec.size()-2){
		chmax(ans, min(vec[i+1], r+1) - max(vec[i], l-1) - 1);
	}
	cout << ans << endl;
	
	return 0;
}